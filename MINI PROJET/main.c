#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "grille.h"
#include "serpent.h"
#include "Liste_Section.h"


int main(int argc, char **argv){
    int L, C;
    L = strtol(argv[1], NULL , 10);
    C = strtol(argv[2], NULL , 10);
    printf("hello\n");
    serpent * s = creer_serpent();
    printf("%s\n",s->l_serpent->premier->couleur);
    grille * g = Grille_allouer(L,C);
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
    Grille_desallouer(g);
    printf("%d\n",g->n);
    //detruire_liste_section(s->l_serpent);
    /*if( s !=  NULL){
        if (s->l_serpent != NULL ) free(s->l_serpent);
        free(s);
    }*/
    printf("%d\n",s->x);
    serpent_desallouer(s);
    printf("%d\n",s->x);
    return EXIT_SUCCESS;
}