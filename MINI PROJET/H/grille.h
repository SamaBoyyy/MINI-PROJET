#ifndef GRILLE_H
#define GRILLE_H

#include "serpent.h"


typedef struct grille_s {
    unsigned n;
    unsigned m;
    char * **tab;
    coord fruit;
} grille;

grille * Grille_allouer( unsigned n, unsigned m);

void Grille_vider( grille *g );

void Grille_tirage_fruit( grille *g , serpent *s);

void Grille_remplir( grille *g, serpent *s );

void Grille_desallouer( grille *g );

void Grille_redessiner( grille *g);


void Grille_remplir_bis(grille * g ,serpent * s);

#endif 
