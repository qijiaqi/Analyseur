#include "etat.h"
#include "automate.h"
#include <iostream>
#include <climits>

int E0::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        case DEBORD:
            return 2;
		case INT:
			automate.decaler(s, new E3());
			break;
		case OPENPAR:
			automate.decaler(s, new E2());
			break;
        case EXP:
            automate.decaler(s, new E1());
            break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return 3;
	}
	return 1;
}

int E1::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        case DEBORD:
            return 2;
		case PLUS:
			automate.decaler(s, new E4());
			break;
		case MULT:
			automate.decaler(s, new E5());
			break;
		case FIN:
            return 0;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
            return 3;
	}
	return 1;
}

int E2::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        case DEBORD:
            return 2;
		case INT:
			automate.decaler(s, new E3());
			break;
		case OPENPAR:
			automate.decaler(s, new E2());
			break;
        case EXP:
            automate.decaler(s, new E6());
            break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return 3;
	}
	return 1;
}

int E3::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        int v;
        case DEBORD:
            return 2;
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			v = ((Entier*)automate.pile_s.top()) -> getVal();
            automate.pile_s.pop();
			automate.reduire(1, new Exp(v));
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return 3;
	}
	return 1;
}

int E4::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        case DEBORD:
            return 2;
		case INT:
			automate.decaler(s, new E3());
			break;
		case OPENPAR:
			automate.decaler(s, new E2());
			break;
        case EXP:
            automate.decaler(s, new E7());
            break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return 3;
	}
	return 1;
}

int E5::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        case DEBORD:
            return 2;
		case INT:
			automate.decaler(s, new E3());
			break;
		case OPENPAR:
			automate.decaler(s, new E2());
			break;
        case EXP:
            automate.decaler(s, new E8());
            break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
            return 3;
	}
	return 1;
}

int E6::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        case DEBORD:
            return 2;
		case PLUS:
			automate.decaler(s, new E4());
			break;
		case MULT:
			automate.decaler(s, new E5());
			break;
		case CLOSEPAR:
			automate.decaler(s, new E9());
            break;
        case EXP:
            automate.decaler(s, new E8());
            break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return 3;
	}
	return 1;
}

int E7::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        int v1, v2;
        bool deb;
        case DEBORD:
            return 2;
		case MULT:
			automate.decaler(s, new E5());
			break;
		case PLUS:
		case CLOSEPAR:
		case FIN:
			v1 = ((Exp*)automate.pile_s.top()) -> getVal();
			automate.pile_s.pop();
            automate.pile_s.pop();//opérateur +
			v2 = ((Exp*)automate.pile_s.top()) -> getVal();
            automate.pile_s.pop();
            deb = (INT_MAX - v2 < v1);//débordement de INT
            if(!deb) {
                automate.reduire(3, new Exp(v1+v2));
            } else {
                return 2;
            }
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
            return 3;
	}
	return 1;
}

int E8::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        int v1, v2;
        bool deb;
        case DEBORD:
            return 2;
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			v1 = ((Exp*)automate.pile_s.top()) -> getVal();
			automate.pile_s.pop();
            automate.pile_s.pop();//opérateur *
			v2 = ((Exp*)automate.pile_s.top()) -> getVal();
            automate.pile_s.pop();
            deb = ((v1*v2)/v2 != v1);//débordement de INT
            if(!deb) {
                automate.reduire(3, new Exp(v1*v2));
            } else {
                return 2;
            }
            break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return 3;
	}
	return 1;
}

int E9::transition(Automate &automate, Symbole *s) {
	switch (*s) {
        int v;
        case DEBORD:
            return 2;
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			automate.pile_s.pop();// openpar (
			v = ((Exp*)automate.pile_s.top()) -> getVal();
            automate.pile_s.pop();
			automate.pile_s.pop();// closepar )
			automate.reduire(3, new Exp(v));
			break;
		default:
			automate.decaler(new Symbole(ERREUR), NULL);
			return 3;
	}
	return 1;
}