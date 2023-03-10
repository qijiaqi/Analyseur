#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Automate;

class Etat {
    public : 
        Etat(string s) : name(s) { }
        virtual ~Etat() { }
        virtual int transition(Automate& a, Symbole* s) {return 1;}// FIN 0 CAL 1 DEB 2 ERR 3
    protected : 
        string name;
};

class E0 : public Etat {
    public : 
        E0() : Etat("E0") { }
        virtual ~E0() { }
        int transition(Automate& a, Symbole* s);
};

class E1 : public Etat {
    public : 
        E1() : Etat("E1") { }
        virtual ~E1() { }
        int transition(Automate& a, Symbole* s);
};

class E2 : public Etat {
    public : 
        E2() : Etat("E2") { }
        virtual ~E2() { }
        int transition(Automate& a, Symbole* s);
};

class E3 : public Etat {
    public : 
        E3() : Etat("E3") { }
        virtual ~E3() { }
        int transition(Automate& a, Symbole* s);
};

class E4 : public Etat {
    public : 
        E4() : Etat("E4") { }
        virtual ~E4() { }
        int transition(Automate& a, Symbole* s);
};

class E5 : public Etat {
    public : 
        E5() : Etat("E5") { }
        virtual ~E5() { }
        int transition(Automate& a, Symbole* s);
};

class E6 : public Etat {
    public : 
        E6() : Etat("E6") { }
        virtual ~E6() { }
        int transition(Automate& a, Symbole* s);
};

class E7 : public Etat {
    public : 
        E7() : Etat("E7") { }
        virtual ~E7() { }
        int transition(Automate& a, Symbole* s);
};

class E8 : public Etat {
    public : 
        E8() : Etat("E8") { }
        virtual ~E8() { }
        int transition(Automate& a, Symbole* s);
};

class E9 : public Etat {
    public : 
        E9() : Etat("E9") { }
        virtual ~E9() { }
        int transition(Automate& a, Symbole* s);
};