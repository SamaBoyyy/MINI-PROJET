# Option du compilateur
CFLAGS=-Wall -std=c99 -Wfatal-errors

OBJETS= serpent.o Liste_Section.o grille.o main.o
PROG=programme

all: $(OBJETS)
	gcc $(CFLAGS) $(OBJETS) -o $(PROG) -lncurses

grille.o: grille.c grille.h
	gcc -c $(CFLAGS) grille.c -lncurses

Liste_Section.o: Liste_Section.c Liste_Section.h
	gcc -c $(CFLAGS) Liste_Section.c -lncurses

serpent.o: serpent.c serpent.h Liste_Section.h
	gcc -c $(CFLAGS) serpent.c -lncurses

main.o: main.c grille.h serpent.h
	gcc -c $(CFLAGS) main.c -lncurses

clean:
	rm $(PROG) $(OBJETS)