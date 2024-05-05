# Option du compilateur
CFLAGS=-Wall -std=c99 -Wfatal-errors

OBJETS= grille.o main.o
PROG=programme

all: $(OBJETS)
	gcc $(OBJETS) -o $(PROG)

grille.o: grille.c grille.h
	gcc -c $(CFLAGS) grille.c

main.o: main.c grille.h
	gcc -c $(CFLAGS) main.c

clean:
	rm $(PROG) $(OBJETS)