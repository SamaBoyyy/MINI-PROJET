#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "serpent.h"
#include "Liste_Section.h"


serpent * creer_serpent(){
    srand(time(NULL));
    //allouer
    serpent * s = malloc(sizeof(serpent));
    printf("1");
    s->l_serpent = nouvelle_liste_section();
    s->l_serpent->premier = nouvelle_Section(1); //  IL FAUT INITIALISER LE MAILLON

    printf("2");
    s->x = 5;  // ON NE PEUT FAIRE UN SRAND CAR LE CALCULE SE FAIT SI VITE QUE LE SERPENT ET AU MEME ENDROIT QU'AU FRUIT.
    s->y = 5;
    //mettre couleur section
    printf("3");
    int c = (rand() % 7) + 41; // de 41 à 47
    sprintf(s->l_serpent->premier->couleur , "\33[%dm S\33[00m", c);
    printf("4\n");
    //arrangement liste
    

    s->l_serpent->premier->suivant = s->l_serpent->dernier;
    // s->l_serpent->dernier->suivant = NULL;  // !!! SEG FAULT CAR ESPACE NON ALLOUER !!!
    
    printf("5");
    return s;
}

void serpent_desallouer(serpent *s){
    if( s != NULL ){
        if( s->l_serpent != NULL )
        detruire_liste_section( &(s->l_serpent) );
        free(s->l_serpent);
        s->l_serpent = NULL;          
        free(s);
        
    }
}