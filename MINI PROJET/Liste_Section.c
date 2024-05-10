#include <stdio.h>
#include <stdlib.h>
#include "Liste_Section.h"


/* Alloue sur le tas de la mémoire pour un maillon de valeur v */
/* et renvoie l'adresse du maillon */
Section *nouvelle_Section (int taille) {
  Section *m = malloc(sizeof(Section));
  m->taille = taille;
  m->couleur = malloc(8*sizeof(char));
  m->suivant = NULL;
  return m;
}

/* Libère l'espace mémoire occupé sur le tas par le maillon d'adresse m */
void detruire_Section (Section **m) {
  if (*m != NULL) {
    if( (*m)->couleur != NULL ) free((*m)->couleur);
    free(*m);
    *m = NULL;
  }
}

/* Alloue sur le tas de la mémoire pour une liste, */
/* initialise cette liste à la liste vide */
/* et renvoie l'adresse de la liste allouée */
liste_section *nouvelle_liste_section() {
  liste_section *l = malloc(sizeof(liste_section));
  l->premier = NULL;
  l->dernier = NULL;
  l->longueur = 0;
  return l;
}

/** Teste si la liste est vide */
/* renvoie un entier ≠ 0 si la liste d'adresse l est vide, 0 sinon */
int est_vide_liste_section(const liste_section *l) {
  return (l->premier == NULL);
}

/** Renvoie le nombre de maillons dans la liste d'adresse l */
int longueur_liste_section(const liste_section *l) {
  return l->longueur;
}

/* Affiche les couleur des sections de la liste d'adresse l */
/* Anciennement Afficher_liste_int, qui affiche les valeurs de la listes */
void afficher_liste_couleur(const liste_section *l) {
  Section *m;
  for (m = l->premier; m != NULL; m = m->suivant) {
     printf("%s ", m->couleur);
  }
  printf("\n");
}

/* Insère le maillon d'adresse m au début de la liste d'adresse l */
void ajouter_maillon_debut_liste_section(liste_section *l, Section *m) {
  if (est_vide_liste_section(l)) {  l->dernier = m; }
  m->suivant = l->premier;
  l->premier = m;
  ++l->longueur;
}


/* Insère le maillon d'adresse m à la fin de la liste d'adresse l */
void ajouter_section_fin_liste_section(liste_section *l, Section *m) {
  m->suivant = NULL;
  if (est_vide_liste_section(l)) {
    l->premier = m;
  }
  else {
  l->dernier->suivant = m;
  }
  l->dernier = m;
  ++l->longueur;
}

/** Extrait le premier maillon de la liste d'adresse l */
/* et renvoie l'adresse du maillon extrait */
/** Renvoie NULL si la liste est vide */
Section *extraire_maillon_debut_liste_section(liste_section *l) {
  Section *m = l->premier;
  if (m != NULL) {
    l->premier = m->suivant;
    --l->longueur;
    if (est_vide_liste_section(l)) { l->dernier = NULL; }
    m->suivant = NULL;
  }
  return m;
}

/** Extrait le dernier maillon de la liste d'adresse l */
/* et renvoie l'adresse du maillon extrait */
/* Renvoie NULL si la liste est vide */
Section *extraire_maillon_fin_liste_section(liste_section *l) {
  Section *m = l->premier, *res;
  if (m == NULL) {  return m; }
  --l->longueur;
  if (m->suivant == NULL) {
    l->premier = NULL;
    l->dernier = NULL;
    return m;
  }
  while (m->suivant != NULL) { /*was written m->suivant->suivant; changed it to m->suivant; maybe that's my bad; but there were an error;*/ 
    m = m->suivant;
  }
  l->dernier = m;
  res = m->suivant;
  m->suivant = NULL;
  return res;
}

/** Libère l'espace mémoire occupé sur le tas par la liste et tous ses maillons */
void detruire_liste_section(liste_section **l) {
  if (*l != NULL) {
    while (!est_vide_liste_section(*l)) {
      Section *m = extraire_maillon_debut_liste_section(*l);
      detruire_Section(&m);
    }
    free(*l);
    *l = NULL;
  }
}
