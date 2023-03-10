all: calcul

calcul: lexer.o symbole.o etat.o automate.o main.o
	g++ -o calcul lexer.o symbole.o etat.o automate.o main.o

lexer.o: lexer.cpp lexer.h
	g++ -o lexer.o -c lexer.cpp

symbole.o: symbole.cpp symbole.h
	g++ -o symbole.o -c symbole.cpp

etat.o: etat.cpp etat.h
	g++ -o etat.o -c etat.cpp

automate.o: automate.cpp automate.h
	g++ -o automate.o -c automate.cpp

main.o: main.cpp symbole.h lexer.h etat.h
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o

mrproper: clean
	rm -rf calcul