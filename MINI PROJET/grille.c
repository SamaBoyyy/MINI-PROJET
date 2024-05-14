#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "grille.h"

grille * Grille_allouer ( unsigned n, unsigned m ){
    int i ;
    grille *g= malloc(sizeof(grille));  //allocation memoire pour le type grille (reserve d'un espace de taille type grille)
    if (g == NULL)  return NULL;     // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    (g->m) = m;
    (g->n) = n;
    (g->tab) = malloc(n * sizeof(char *));  //alocation memoire de la premiere collonne de taille type pointeur char
    if (g->tab == NULL) return NULL;        // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    for( i = 0 ; i < n ; i++ ){
        g->tab[i] = calloc(m, sizeof(char * )); //alocation memoire des n ligne de taille m fois type pointeur char
        if (g->tab[i] == NULL) return NULL;     // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    }
    for( i =  0; i < n  ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
          *(*(g->tab + i)+j) = malloc(8 * sizeof(char));    //alocation memoire qui permet à chaque pointeur du tableau à deux dims de pointer vers un espace de 8 caractere
            if (*(*(g->tab + i)+j) == NULL) return NULL;    // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
        }
    }
    
    return g;
}


void Grille_vider (grille *g ){
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
                strcpy((*(*(g->tab + i) + j)), "\33[00m  \33[00m"); //met la valeur une couleur verte puis l'arrete avec une couleur noir
            }
        }
    }  



void Grille_tirage_fruit(grille *g, serpent * s){
    srand(time(NULL));
    do{
        g->fruit.x=rand()%(g->n);
        g->fruit.y=rand()%(g->m);
    } while (g->fruit.x == s->x  || g->fruit.y == s->y);
    printf("g->fruit.x= %d || g->fruit.y= %d \n",g->fruit.x,g->fruit.y);
}


void Grille_remplir( grille *g, serpent *s ){
    strcpy(*(*(g->tab + (g->fruit.x)) + (g->fruit.y)) , "\33[41m  ");
    strcpy(*(*(g->tab + (s->x)) + (s->y)) , s->l_serpent->premier->couleur);
}

void Grille_desallouer(grille *g){
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
            *(*(g->tab + i) +j)= NULL ;
            free(*(*(g->tab + i) +j));
        }
    }
    
    free(g->tab);
    free(g);
    
}

//void Grille_redessiner(grille *g){
//    for ( int i = 0 ; i < g->n  ; i++ ){ //affichage
//        for( int j = 0 ; j < g->m ; j++ ){
//            printf("%s", *(*(g->tab + i) +j));
//        }
//        printf("\n");
//    }
//}

void Grille_redessiner(grille *g){
    for (int i = 0; i <= g->n+1; i++)
    {
        printf("\x1b[2;42;97m==\33[00m");
    }
    printf("\33[1E");

    for ( int i = 0 ; i < g->n ; i++ ){
        printf("\x1b[2;42;97m#+\33[00m");
        for ( int j = 0 ; j < g->m ; j++ ){

                printf("%s", *(*(g->tab + i) + j));
        }
        printf("\x1b[2;42;97m+#\33[00m");
        printf("\33[1E");
    }

    for (int i = 0; i <= g->n+1; i++)
    {
        printf("\x1b[2;42;97m==\33[00m");
    }
    printf("\33[1E");
}