#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    grille *g= malloc(sizeof(grille));  //allocation memoire pour le type grille (reserve d'un espace de taille type grille)
    if (g == NULL) return NULL;         // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    (g->m) = m;
    (g->n) = n;
    (g->tab) = malloc(n * sizeof(char *));  //alocation memoire de la premiere collonne de taille type pointeur char
    if (g->tab == NULL) return NULL;        // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    for( i = 0 ; i < m ; i++ ){
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


void Grille_vide (grille *g ){
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
            *(*(g->tab + i) +j) ="\33[41m 1\33[00m"; //met la valeur une couleur verte puis l'arrete avec une couleur noir
        }
    }
    
}

void Grille_tirage_fruit(grille *g){
    srand(time(NULL));
    g->fruit.x=rand()%(g->n);
    g->fruit.y=rand()%(g->m);
    printf("g->fruit.x= %d || g->fruit.y= %d \n",g->fruit.x,g->fruit.y);
}


void Grille_remplir(grille *g){
    *(*(g->tab + (g->fruit.x)) + (g->fruit.y)) = "\33[00m  ";
}

void Grille_desalouer(grille *g){
    for ( int i = 0 ; i < g->n  ; i++ ){
        for( int j = 0 ; j < g->m ; j++ ){
            *(*(g->tab + i) +j)= NULL ;
            free(*(*(g->tab + i) +j));
        }
    }
    
    free(g->tab);
    free(g);
    
}

int main(int argc, char const *argv[])
{
    grille *g = Grille_allouer(10,12);
    if (g == NULL)
    {
        printf("\33[91mMEMOIRE INSUFISANTE\n");
        return EXIT_FAILURE;
    }
    Grille_vide(g);
    Grille_tirage_fruit(g);
    Grille_remplir(g);
    for ( int i = 0 ; i < g->n  ; i++ ){ //affichage
        for( int j = 0 ; j < g->m ; j++ ){
            printf("%s", *(*(g->tab + i) +j));
        }
        printf("\n");
    }
    printf("%d\n",g->n);
    Grille_desalouer(g);
    printf("%d\n",g->n);
    return EXIT_SUCCESS;
}
