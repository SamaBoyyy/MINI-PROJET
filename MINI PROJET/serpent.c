#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Liste_Section.h"
#include "grille.h"
#include "serpent.h"


struct serpent_s * creer_serpent(){
    srand(time(NULL));
    //allouer
    struct serpent_s * s = malloc(sizeof(struct serpent_s));
    s->l_serpent = nouvelle_liste_section();
    s->x = rand() % 20;
    s->y = rand() % 20;
    //mettre couleur section
    int c = (rand() % 7) + 41; // de 41 à 47

    s->l_serpent->premier->couleur = "\33[%dm 1\33[00m", c;
}