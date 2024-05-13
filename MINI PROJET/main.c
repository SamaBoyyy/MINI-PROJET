#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "serpent.h"
#include "Liste_Section.h"
#include <ncurses.h>
//#include "Fonctions_Jeu.h"

int main(int argc, char *argv[]){

    /*if( argc != 5) {
        printf("Usage : unsigned unsigned unsigned unsigned\n Coordonnee x | Coordonnee y | Delai desire | Quel Jeu ?\n");
        return EXIT_FAILURE;
    }
    unsigned x, y, delai, jeu; // Dimensions de la grille
    x     = strtoul( argv[1], NULL, 10);
    y     = strtoul( argv[2], NULL, 10);
    delai = strtoul( argv[3], NULL, 10);
    jeu   = strtoul( argv[4], NULL, 10);
*/
    printf("hello\n");
    serpent * s = creer_serpent();
    printf("%s\n",s->l_serpent->premier->couleur);
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
    Grille_desallouer(g);
    printf("%d\n",g->n);
    //detruire_liste_section(s->l_serpent);
    /*if( s !=  NULL){
        if (s->l_serpent != NULL ) free(s->l_serpent);
        free(s);
    }*/
    //jouer_jeu_serpent(  delai, g, s);
    printf("%d\n",s->x);
    serpent_desallouer(s);
    printf("%d\n",s->x);
    return EXIT_SUCCESS;
}