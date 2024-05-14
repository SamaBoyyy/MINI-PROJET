#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "serpent.h"
#include "Liste_Section.h"


serpent * creer_serpent(){

    //allouer
    serpent * s = malloc(sizeof(serpent));
    printf("1");
    s->l_serpent = nouvelle_liste_section();
    s->l_serpent->premier = nouvelle_Section(1); //  IL FAUT INITIALISER LE MAILLON
    s->l_serpent->dernier = nouvelle_Section(1);
    s->x = 2;  // ON NE PEUT PAS FAIRE UN SRAND CAR LE CALCULE SE FAIT SI VITE QUE LE SERPENT ET AU MEME ENDROIT QU'AU FRUIT.
    s->y = 2;
    //mettre couleur section
    sprintf(s->l_serpent->premier->couleur , "\33[%dm S\33[00m", couleur_aleatoire());
    printf("4");
    
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

int couleur_aleatoire(){
    srand(time(NULL));
    int c = (rand() % 7) + 41;  // de 41 à 47
    return c;

}

void grandir_serpent(serpent * s){
    int cpt = 1 ; 
    

}