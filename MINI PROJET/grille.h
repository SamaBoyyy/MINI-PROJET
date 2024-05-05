#ifndef GRILLE_H
#define GRILLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct coord_s {
    unsigned x;
    unsigned y;
} coord;

typedef struct grille_s {
    unsigned n;
    unsigned m;
    char **tab;
    coord fruit;
} grille;

grille * Grille_allouer ( unsigned n, unsigned m);

void Grille_vider ( grille *g );

void Grille_tirage_fruit ( grille *g );

void Grille_remplir ( grille *g );

void Grille_desallouer ( grille *g );

void Grille_redessiner( grille *g);

#endif // GRILLE_H
