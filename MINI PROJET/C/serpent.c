#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../H/serpent.h"
#include "../H/Liste_Section.h"
// #include "grille.h"

int CPT = 1;

serpent *creer_serpent()
{

    // allouer
    serpent *s = malloc(sizeof(serpent));
    s->l_mouvement = malloc(sizeof(liste_mouvement));
    s->l_mouvement->l_dernier = nouveau_mouvement();
    s->l_mouvement->l_premier = nouveau_mouvement();
    s->l_mouvement->l_premier->suivant = s->l_mouvement->l_dernier;
    s->l_serpent = nouvelle_liste_section();
    s->l_serpent->premier = nouvelle_Section(1); //  IL FAUT INITIALISER LE MAILLON
    s->l_serpent->longueur = 1;
    s->x = 2; // ON NE PEUT PAS FAIRE UN SRAND CAR LE CALCULE SE FAIT SI VITE QUE LE SERPENT ET AU MEME ENDROIT QU'AU FRUIT.
    s->y = 2;
    // mettre couleur section
    sprintf(s->l_serpent->premier->couleur, "\33[%dm S\33[00m", couleur_aleatoire());

    return s;
}

void serpent_desallouer(serpent *s)
{
    if (s != NULL)
    {
        if (s->l_serpent != NULL)
            detruire_liste_section(&(s->l_serpent));
        free(s->l_serpent);
        s->l_serpent = NULL;
        free(s);
    }
}

int couleur_aleatoire()
{
    srand(time(NULL));
    int c = (rand() % 7) + 41; // de 41 à 47
    return c;
}

void grandir_serpent(serpent *s)
{
    srand(time(NULL));
    int t = rand() % 5 + 1;
    if (CPT == 1)
    {
        s->l_serpent->dernier = nouvelle_Section(t);
        s->l_serpent->premier->suivant = s->l_serpent->dernier;
        sprintf(s->l_serpent->dernier->couleur, "\33[%dmlo\33[00m", couleur_aleatoire());
        grandir_mouvement(s->l_mouvement, t);
    }
    else
    {
        Section *sn = nouvelle_Section(t);
        sprintf(sn->couleur, "\33[%dmlo\33[00m", couleur_aleatoire());
        ajouter_section_fin_liste_section(s->l_serpent, sn);
        grandir_mouvement(s->l_mouvement, t);
    }
    CPT++;
}

void grandir_mouvement(liste_mouvement *l, int taille)
{
    mouvement *m1;

    for (int i = 0; i < taille; i++)
    {
        m1 = nouveau_mouvement();
        ajouter_mouvement_fin_liste_mouvement(l, m1);
    }
}
void ajouter_mouvement_fin_liste_mouvement(liste_mouvement *l, mouvement *m)
{
    m->suivant = NULL;
    if (est_vide_liste_mouvement(l))
    {
        l->l_premier = m;
    }
    else
    {
        l->l_dernier->suivant = m;
    }
    l->l_dernier = m;
    ++l->longueur;
}

mouvement *nouveau_mouvement()
{ // Initialise un maillon mouvement;
    mouvement *m = malloc(sizeof(mouvement));
    m->position = malloc(sizeof(coord));
    m->suivant = NULL;
    return m;
}

int est_vide_liste_mouvement(const liste_mouvement *l)
{
    return (l->l_premier == NULL);
}

void haut(mouvement *m_mv, int tmpx, int tmpy)
{
    m_mv->position->x = tmpx + 1;
    m_mv->position->y = tmpy;
}

void bas(mouvement *m_mv, int tmpx, int tmpy)
{
    m_mv->position->x = tmpx;
    m_mv->position->y = tmpy - 1;
    tmpx = m_mv->position->x;
    tmpy = m_mv->position->y;
}

void droite(mouvement *m_mv, int tmpx, int tmpy)
{
    m_mv->position->x = tmpx;
    m_mv->position->y = tmpy - 1;
}

void gauche(mouvement *m_mv, int tmpx, int tmpy)
{
    m_mv->position->x = tmpx;
    m_mv->position->y = tmpy + 1;
    tmpx = m_mv->position->x;
    tmpy = m_mv->position->y;
}

int SerpentHeadHitQueue ( serpent * s ) {
     mouvement *mv = s->l_mouvement->l_premier;
    mv = mv->suivant;

    while (mv != NULL)
    {
        if (mv->position->x == s->x && mv->position->y == s->y)
            return 1;
        mv = mv->suivant;
    }
    return 0;
}
