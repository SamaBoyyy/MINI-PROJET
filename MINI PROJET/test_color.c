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
    grille *g=NULL;
    (g->m) = m;
    (g->n) = n;
    (g->tab) = malloc(n * sizeof(char *)); 
    for( i = 0 ; i < m ; i++ ){
        g->tab[i] = calloc(m, sizeof(char * ));
    }
    for( i =  0; i < n  ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
          *(*(g->tab + i)+j) = malloc(8 * sizeof(char));
        }
    }
    return g;
}

int main(int argc, char const *argv[])
{
    printf("H");
    grille *g = Grille_allouer(10, 10);
    printf("ELLo");
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
            *(*(g->tab + i) +j) ="\33[00  ";
        }
    }
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
            printf("%s", *(*(g->tab + i) +j));
        }
        printf("\n");
    }

    return 0;
}
