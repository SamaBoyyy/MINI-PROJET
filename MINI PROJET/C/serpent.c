#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "serpent.h"
#include "Liste_Section.h"
//#include "grille.h"

int CPT=1;

serpent * creer_serpent(){

    //allouer
    serpent * s = malloc(sizeof(serpent));
    s->l_mouvement = malloc(sizeof(liste_mouvement));
    s->l_mouvement->l_dernier = nouveau_mouvement();
    s->l_mouvement->l_premier = nouveau_mouvement();
    s->l_mouvement->l_premier->suivant = s->l_mouvement->l_dernier;
    printf("1");
    s->l_serpent = nouvelle_liste_section();
    s->l_serpent->premier = nouvelle_Section(1); //  IL FAUT INITIALISER LE MAILLON
    
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
    srand(time(NULL));
    int t = rand()%5+1;
    if( CPT == 1 ){
        s->l_serpent->dernier = nouvelle_Section(t);
        s->l_serpent->premier->suivant = s->l_serpent->dernier;
        sprintf(s->l_serpent->dernier->couleur , "\33[%dm S\33[00m", couleur_aleatoire());
    }
    else{
        Section * sn = nouvelle_Section(t);
        sprintf(sn->couleur , "\33[%dm S\33[00m", couleur_aleatoire());
        ajouter_section_fin_liste_section(s->l_serpent , sn);
    }
    CPT++;
}

mouvement * nouveau_mouvement(){ // Initialise un maillon mouvement;
    mouvement *m=malloc(sizeof(mouvement));
    m->mouvement = 0;
    m->position = NULL;
    m->suivant = NULL;
    return m;
}
