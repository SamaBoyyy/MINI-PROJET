# Option du compilateur
CFLAGS=-Wall -std=c99 -Wfatal-errors

OBJETS= serpent.o Liste_Section.o grille.o  Fonctions_Jeu_1_serpent.o main.o
PROG= programme

all: $(OBJETS)
	gcc $(CFLAGS) $(OBJETS) -o $(PROG) -lncurses ;rm $(OBJETS)

grille.o: /C/grille.c /H/grille.h /H/serpent.h
	gcc -c $(CFLAGS) /C/grille.c -lncurses

Liste_Section.o: /C/Liste_Section.c /H/Liste_Section.h
	gcc -c $(CFLAGS) /C/Liste_Section.c -lncurses

serpent.o: /C/serpent.c /H/serpent.h /H/Liste_Section.h 
	gcc -c $(CFLAGS) /C/serpent.c -lncurses

Fonctions_Jeu_1_serpent.o: /C/Fonctions_Jeu_1_serpent.c /H/Fonctions_Jeu.h /H/grille.h /H/serpent.h
	gcc -c $(CFLAGS) /C/Fonctions_Jeu_1_serpent.c -lncurses

main.o: main.c /H/grille.h /H/serpent.h /H/Liste_Section.h /H/Fonctions_Jeu.h
	gcc -c $(CFLAGS) /C/main.c -lncurses

clean:
	rm $(PROG)