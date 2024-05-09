#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "serpent.h"
#include "Liste_Section.h"


struct serpent_s * creer_serpent(){
    srand(time(NULL));
    //allouer
    struct serpent_s * s = malloc(sizeof(struct serpent_s));
    s->l_serpent = nouvelle_liste_section();
    s->x = rand() % 20;
    s->y = rand() % 20;
    //mettre couleur section

    /*
    int c = (rand() % 7) + 41; // de 41 à 47
    s->l_serpent->premier->couleur = ("\33[%dm 1\33[00m", c);
    */

    s->l_serpent->premier->couleur = "\33[42m X\33[00m";
    s->l_serpent->premier->suivant = s->l_serpent->dernier;
    s->l_serpent->dernier->suivant = NULL;
    return s;
}

void serpent_desallouer(serpent * s){

    if( s != NULL ){
        if( s->l_serpent != NULL )
            detruire_liste_section( s->l_serpent );
        free(s->l_serpent);
        s->l_serpent = NULL;
        free(s);
        s = NULL;
    }

}