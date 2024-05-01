#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "grille.h"

grille * Grille_allouer ( unsigned n, unsigned m);
void Grille_vider ( grille *g );
void Grillage_tirage_fruit ( grille *g );
void Grille_remplir ( grille *g );
void desallouer ( grille *g );

int main(int argc, char *argv[]){

}

grille * Grille_allouer ( unsigned n, unsigned m ){
    grille *g;
    g->tab = malloc(n * m * sizeof(char)); 
    for( int i = 0 ; i < n  ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            *(*(g->tab + i)+j) = malloc(8* sizeof(char));
        }
    }
    return g;
}

void Grille_vider ( grille *g ){
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
            *(*(g->tab + i) +j) ="\33[00  ";
        }
    }
}

void Grillage_tirage_fruit ( grille *g ){
    
}