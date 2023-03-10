#include <iostream>
#include <climits>
#include "lexer.h"
#include "Automate.h"

int main(void) { 
   string chaine;
   //INT_MAX = 2147483647, à tester : 2147483647+1, 2147483647*2, 2147483648
   //cout << (2147483647+1)-1 << endl << (2147483647)*2/2 << endl << INT_MAX << endl;
   cout << "****************************************" << endl;
   cout << "+ Bienvenue sur notre calculatrice :)  +" << endl;
   cout << "+ Tapez 1 pour calculer une expression +" << endl;
   cout << "+ Tapez 2 pour quitter la calculatrice +" << endl;
   cout << "****************************************" << endl;
   int choix;
   bool fin = false;
   Automate* a;
   do {
      cin >> choix;
		if (cin.fail()) {
         cin.clear();
         cin.ignore();
         cout<<"Choix 1 ou 2 ?"<<endl;
      } else {
         switch (choix) {
            case 1:
               cout << "Expression à calculer : " << endl;
               cin >> chaine;
               a = new Automate(chaine);
               a->evaluer();
               if (a->afficher() == -1) {
                  cout << "Expression invalide..." << endl;
               } else if (a->afficher() == -2) {
                  cout << "Débordement de INT..." << endl;
               } else {
                  cout << "Réponse : " << chaine << " = " << a->afficher() << endl;
               } 
               cout << "****************************" << endl << "continuer(1) ou quitter(2) ?" << endl;
               break;
            case 2:
               cout << "Merci de votre utilisation ~" << endl;
               fin = true;
               break;
            default:
               cout << "Choix 1 ou 2 ?" << endl;
               break;
         }
      }
   } while (!fin);
   return 0;
}

