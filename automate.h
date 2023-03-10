#pragma once

#include <string>
#include <stack>
#include "lexer.h"
#include "symbole.h"
#include "etat.h"
using namespace std;

class Automate {
    public :
        Automate(string flux);
        virtual ~Automate();
        void decaler(Symbole* s, Etat* e);
        void reduire(int n, Symbole* s);
        void evaluer();
        int afficher();
        stack<Symbole*> pile_s;
        stack<Etat*> pile_e;
    protected : 
        Lexer* lexer;
        int retour_auto = 1;// ERR 3 DEB 2 CAL 1 FIN 0   
};