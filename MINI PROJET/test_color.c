#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct coord_s {
    unsigned x;
    unsigned y;
} coord;

typedef struct grille_s {
    unsigned n;
    unsigned m;
    char * **tab;
    coord fruit;
} grille;

grille * Grille_allouer ( unsigned n, unsigned m ){
    int i ;
    grille *g= malloc(sizeof(grille)); //allocation memoire pour le type grille (reserve d'un espace de taille type grille)
    (g->m) = m;
    (g->n) = n;
    (g->tab) = malloc(n * sizeof(char *)); //alocation memoire de la premiere collonne de taille type pointeur char
    for( i = 0 ; i < m ; i++ ){
        g->tab[i] = calloc(m, sizeof(char * )); //alocation memoire des n ligne de taille m fois type pointeur char
    }
    for( i =  0; i < n  ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
          *(*(g->tab + i)+j) = malloc(8 * sizeof(char)); //alocation memoire qui permet à chaque pointeur du tableau à deux dims de pointer vers un espace de 8 caractere
        }
    }
    return g;
}

int main(int argc, char const *argv[])
{
    printf("H");
    grille *g = Grille_allouer(10, 10);
    printf("ELLo\n");
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
            *(*(g->tab + i) +j) ="\33[42m   \33[00m"; //met la valeur une couleur verte puis l'arrete avec une couleur noir
        }
    }
    for ( int i = 0 ; i < g->n  ; i++ ){ //affichage
        for( int j = 0 ; j < g->m ; j++ ){
            printf("%s", *(*(g->tab + i) +j));
        }
        printf("\n");
    }

    return 0;
}
