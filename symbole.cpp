#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Exp::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Symbole::getID() {
   return this -> ident;
}

int Entier::getVal() {
   return this -> valeur;
}

int Exp::getVal() {
   return this -> valeur;
}

bool Symbole::isTerminal() {
   return true;
}

bool Entier::isTerminal() {
   return Symbole::isTerminal();
}

bool Exp::isTerminal() {
   return false;
}

// Version avec arbre
// int ExpP::getVal() const
// {
//     return gauche->getVal() + droite->getVal();
// }
// 
// int ExpM::getVal () const
// {
//     return gauche->getVal() * droite->getVal();
// }
// 
// int ExpC::getVal () const
// {
//     return valeur;
// }