#ifndef SERPENT_H
#define SERPENT_H
#include "Liste_Section.h"

typedef struct serpent_s{
    unsigned x;
    unsigned y;
    liste_section *l_serpent;
    liste_section *l_mouvement;
}serpent;

typedef enum direction {
    Haut,
    bas,
    Droite,
    Gauche
}direction;




serpent * creer_serpent();
void serpent_desallouer(serpent *s);
int couleur_aleatoire();
void grandir_serpent(serpent * s);

#endif



