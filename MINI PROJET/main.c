#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "serpent.h"
#include "Liste_Section.h"
#include <ncurses.h>

int main(){
    printf("hellol");
    serpent * s = creer_serpent();
    printf("%s",s->l_serpent->premier->couleur);
    grille * g = Grille_allouer(20,20);
    if (g == NULL)
    {
        printf("\33[91mMEMOIRE INSUFISANTE\n");
        return EXIT_FAILURE;
    }
    Grille_vider(g);
    Grille_tirage_fruit(g);
    Grille_remplir(g,s);
    Grille_redessiner(g);
    printf("%d\n",g->n);
    printf("%d\n",g->m);
    Grille_desallouer(g);
    //detruire_liste_section(s->l_serpent);
    /*if( s !=  NULL){
        if (s->l_serpent != NULL ) free(s->l_serpent);
        free(s);
    }*/
    //serpent_desallouer(s);
    return EXIT_SUCCESS;
}