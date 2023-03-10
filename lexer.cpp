#include "lexer.h"
#include <climits>

Symbole * Lexer::Consulter() {
   if (!tampon) {

      if (tete==flux.length())
         tampon = new Symbole(FIN);
      else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               tete++;
               break;
            default:
               bool deb = false;
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     int pre = resultat;
                     resultat = resultat*10+(flux[tete+i]-'0');
                     if((INT_MAX - (flux[tete+i]-'0'))/10 < pre){
                        deb = true;
                        break;
                     }
                     i++;
                  }
                  tete = tete+i;
                  if(!deb) {
                     tampon = new Entier(resultat);
                  } else {
                     tampon = new Symbole(DEBORD);
                  }
               }
               else {
                  tampon = new Symbole(ERREUR);
               }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer() {
   tampon = nullptr;
}

