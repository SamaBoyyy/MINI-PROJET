#ifndef SERPENT_H
#define SERPENT_H
#include "Liste_Section.h"
//#include "grille.h"

typedef struct coord_s {
    unsigned x;
    unsigned y;
} coord;


typedef enum direction {
    Haut,
    bas,
    Droite,
    Gauche
}direction;

typedef struct mouvement_s {
    coord * position;
    struct mouvement_s *suivant;
}mouvement;

typedef struct liste_mouvement_s {
    mouvement *l_premier;
    mouvement *l_dernier;
    int longueur;
}liste_mouvement;

typedef struct serpent_s{
    unsigned x;
    unsigned y;
    liste_section *l_serpent;
    liste_mouvement *l_mouvement ;
    direction dir ;  
}serpent;





serpent * creer_serpent();
void serpent_desallouer(serpent *s);
int couleur_aleatoire();
void grandir_serpent(serpent * s);
void ajouter_mouvement_fin_liste_mouvement(liste_mouvement *l, mouvement *m);
mouvement * nouveau_mouvement();
int est_vide_liste_mouvement(const liste_mouvement *l);
void grandir_mouvement(liste_mouvement *l, int taille);


#endif



