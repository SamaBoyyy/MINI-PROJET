#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "grille.h"
#include "serpent.h"

grille *Grille_allouer(unsigned n, unsigned m)
{
    int i;
    grille *g = malloc(sizeof(grille)); // allocation memoire pour le type grille (reserve d'un espace de taille type grille)
    if (g == NULL)
        return NULL; // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    (g->m) = m;
    (g->n) = n;
    (g->tab) = malloc(n * sizeof(char *)); // alocation memoire de la premiere collonne de taille type pointeur char
    if (g->tab == NULL)
        return NULL; // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    for (i = 0; i < n; i++)
    {
        g->tab[i] = calloc(m, sizeof(char *)); // alocation memoire des n ligne de taille m fois type pointeur char
        if (g->tab[i] == NULL)
            return NULL; // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
    }
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(*(g->tab + i) + j) = malloc(8 * sizeof(char)); // alocation memoire qui permet à chaque pointeur du tableau à deux dims de pointer vers un espace de 8 caractere
            if (*(*(g->tab + i) + j) == NULL)
                return NULL; // Verifie si allorcation memoire a ete possible sinon on renvoie le pointeur NULL
        }
    }

    return g;
}

void Grille_vider(grille *g)
{
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->m; j++)
        {
            strcpy((*(*(g->tab + i) + j)), "\33[00m  \33[00m"); // met la valeur une couleur verte puis l'arrete avec une couleur noir
        }
    }
}

void Grille_tirage_fruit(grille *g, serpent *s)
{
    srand(time(NULL));
    do
    {
        g->fruit.x = rand() % (g->n);
        g->fruit.y = rand() % (g->m);
    } while (g->fruit.x == s->x || g->fruit.y == s->y);
    printf("g->fruit.x= %d || g->fruit.y= %d \n", g->fruit.x, g->fruit.y);
}

void Grille_remplir(grille *g, serpent *s)
{
    strcpy(*(*(g->tab + (g->fruit.x)) + (g->fruit.y)), "\33[41m  ");
    Section *m;
    int sy = s->y;
    char buffer[18];
    for (m = s->l_serpent->premier; m != NULL; m = m->suivant)
    {
        for (int i = 0; i < m->taille; i++)
        {
            sprintf(buffer, "%s", m->couleur);
            strcpy(*(*(g->tab + (s->x)) + (sy + i)), buffer);
        }
        sy += m->taille;
    }
}

void Grille_remplir_bis(grille *g, serpent *s)
{
    strcpy(*(*(g->tab + (g->fruit.x)) + (g->fruit.y)), "\33[41m  ");

    mouvement *m_mv = s->l_mouvement->l_premier;
    char buffer[18];

    int tmpx = s->x;
    int tmpy = s->y;

    for (Section *m = s->l_serpent->premier; m != NULL; m = m->suivant)
    {
        if (m_mv == NULL)
            break;

        m_mv->position->x = tmpx;
        m_mv->position->y = tmpy;
        tmpx = m_mv->position->x;
        tmpy = m_mv->position->y;
        sprintf(buffer, "%s", m->couleur);
        strcpy(*(*(g->tab + (m_mv->position->x)) + (m_mv->position->y)), buffer);

        m_mv = m_mv->suivant;
    }

    /*
    for (mouv = s->l_mouvement->l_premier; mouv != NULL; mouv = mouv->suivant)
    {
        mouv->position->y = s->y;
        mouv->position->x = s->x;
        if (sy != s->y || sx != s->x)
        {
            if (s->dir == Haut)
            {

                sprintf(buffer, "%s", m->couleur);
                strcpy(*(*(g->tab + (mouv->position->x)) + (mouv->position->y)), buffer);

            }
        }
    }
    */
}

void Grille_desallouer(grille *g)
{
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->m; j++)
        {
            *(*(g->tab + i) + j) = NULL;
            free(*(*(g->tab + i) + j));
        }
    }

    free(g->tab);
    free(g);
}

// void Grille_redessiner(grille *g){
//     for ( int i = 0 ; i < g->n  ; i++ ){ //affichage
//         for( int j = 0 ; j < g->m ; j++ ){
//             printf("%s", *(*(g->tab + i) +j));
//         }
//         printf("\n");
//     }
// }

void Grille_redessiner(grille *g)
{
    printf("\33[2J");
    printf("\33[H");

    for (int i = 0; i <= g->m + 1; i++)
    {
        printf("\x1b[2;42;97m==\33[00m");
    }
    printf("\33[1E");

    for (int i = 0; i < g->n; i++)
    {
        printf("\x1b[2;42;97m#+\33[00m");
        for (int j = 0; j < g->m; j++)
        {

            printf("%s", *(*(g->tab + i) + j));
        }
        printf("\x1b[2;42;97m+#\33[00m");
        printf("\33[1E");
    }

    for (int i = 0; i <= g->m + 1; i++)
    {
        printf("\x1b[2;42;97m==\33[00m");
    }
    printf("\33[1E");
}