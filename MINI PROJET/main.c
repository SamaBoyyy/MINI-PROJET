#include <stdlib.h>
#include <stdio.h>
#include "grille.h"
#include <ncurses.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    grille *g = Grille_allouer(10,12);
    if (g == NULL)
    {
        printf("\33[91mMEMOIRE INSUFISANTE\n");
        return EXIT_FAILURE;
    }
    Grille_vider(g);
    Grille_tirage_fruit(g);
    Grille_remplir(g);
    Grille_redessiner(g);
    printf("%d\n",g->n);
    Grille_desalouer(g);
    printf("%d\n",g->n);
    return EXIT_SUCCESS;
}