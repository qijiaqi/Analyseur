#include "automate.h"
#include <iostream>

Automate::Automate(string flux) {
    this -> lexer = new Lexer(flux);
    pile_e.push(new E0());
}

Automate::~Automate() {
    while (!pile_s.empty()) {
        delete pile_s.top();
        pile_s.pop();
    }
    while (!pile_e.empty()) {
        delete pile_e.top();
        pile_e.pop();
    }
}

void Automate::decaler(Symbole* s, Etat* e) {
    pile_s.push(s);
    pile_e.push(e);
    if (s->isTerminal()) { 
        lexer -> Avancer();
    }
}

void Automate::reduire(int n, Symbole* s) {
    for (int i = 0 ; i < n ; ++ i)
    {
        delete(pile_e.top());
        pile_e.pop();
    }
    pile_e.top()->transition(*this,s);
}

void Automate::evaluer() {
    do{
        retour_auto = pile_e.top() -> transition(*this, lexer->Consulter());// ERR 3 DEB 2 CAL 1 FIN 0    
    } while (retour_auto == 1);
}

int Automate::afficher() {
    if (retour_auto == 3) {// pile_s.top() -> getID() == ERREUR
        return -1;
    } else if (retour_auto == 2) {
        return -2;
    } else {
        return ((Exp*)pile_s.top()) -> getVal();
    }
}