#pragma once

#include <string>
using namespace std;

enum Identificateurs { DEBORD, EXP, OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

const string Etiquettes[] = { "DEBORD", "EXP", "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      int getID();
      virtual void Affiche();
      virtual bool isTerminal();
   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      void Affiche();
      bool isTerminal();
      int getVal( );
      virtual ~Entier() { }
   protected : 
      int valeur;
};

class Exp : public Symbole {
   public :
      Exp(int v) : Symbole(EXP), valeur(v) { }
      Exp(Entier e) : Symbole(EXP), valeur(e.getVal()) { }
      void Affiche();
      bool isTerminal();
      int getVal( );
      virtual ~Exp() { }
   protected : 
      int valeur = 0;
};


// Version avec arbre
// class ExpB : public Exp {
//    public :
//       ExpB(Exp& g, Exp& d) : Exp(), g(&g), d(&d) { }
//       virtual ~ExpB() { }
//    protected : 
//       Exp* g;
//       Exp* d;
// };

// class ExpC : public Exp {
//    public :
//       ExpC(int v) : valeur(v) { }
//       virtual ~ExpC() { }
// };

// class ExpM : public ExpB {
//    public :
//       ExpM(Exp& g, Exp& d) : ExpB(g,d) { }
//       virtual ~ExpM() { }
// };

// class ExpP : public ExpB {
//    public :
//       ExpP(Exp& g, Exp& d) : ExpB(g,d) { }
//       virtual ~ExpP() { }
// };
//avec deux pointeurs de type expression, rien à faire pour ()