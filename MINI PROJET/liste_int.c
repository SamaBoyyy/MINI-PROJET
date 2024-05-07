#include <stdio.h>
#include <stdlib.h>
#include "liste_int.h"


/* Alloue sur le tas de la mémoire pour un maillon de valeur v */
/* et renvoie l'adresse du maillon */
struct maillon_int *nouveau_maillon_int (int v) {
  struct maillon_int *m = malloc(sizeof(struct maillon_int));
  m->valeur = v;
  m->suivant = NULL;
  return m;
}

/* Libère l'espace mémoire occupé sur le tas par le maillon d'adresse m */
void detruire_maillon_int (struct maillon_int **m) {
  if (*m != NULL) {
    free(*m);
    *m = NULL;
  }
}

/* Alloue sur le tas de la mémoire pour une liste, */
/* initialise cette liste à la liste vide */
/* et renvoie l'adresse de la liste allouée */
struct liste_int *nouvelle_liste_int() {
  struct liste_int *l = malloc(sizeof(struct liste_int));
  l->premier = NULL;
  l->dernier = NULL;
  l->longueur = 0;
  return l;
}

/** Teste si la liste est vide */
/* renvoie un entier ≠ 0 si la liste d'adresse l est vide, 0 sinon */
int est_vide_liste_int(const struct liste_int *l) {
  return (l->premier == NULL);
}

/** Renvoie le nombre de maillons dans la liste d'adresse l */
int longueur_liste_int(const struct liste_int *l) {
  return l->longueur;
}

/* Affiche les valeurs de la liste d'adresse l */
void afficher_liste_int(const struct liste_int *l) {
  struct maillon_int *m;
  for (m = l->premier; m != NULL; m = m->suivant) {
     printf("%d ", m->valeur);
  }
  printf("\n");
}

/* Insère le maillon d'adresse m au début de la liste d'adresse l */
void ajouter_maillon_debut_liste_int(struct liste_int *l, struct maillon_int *m) {
  if (est_vide_liste_int(l)) {  l->dernier = m; }
  m->suivant = l->premier;
  l->premier = m;
  ++l->longueur;
}


/* Insère le maillon d'adresse m à la fin de la liste d'adresse l */
void ajouter_maillon_fin_liste_int(struct liste_int *l, struct maillon_int *m) {
  m->suivant = NULL;
  if (est_vide_liste_int(l)) {
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
struct maillon_int *extraire_maillon_debut_liste_int(struct liste_int *l) {
  struct maillon_int *m = l->premier;
  if (m != NULL) {
    l->premier = m->suivant;
    --l->longueur;
    if (est_vide_liste_int(l)) { l->dernier = NULL; }
    m->suivant = NULL;
  }
  return m;
}

/** Extrait le dernier maillon de la liste d'adresse l */
/* et renvoie l'adresse du maillon extrait */
/* Renvoie NULL si la liste est vide */
struct maillon_int *extraire_maillon_fin_liste_int(struct liste_int *l) {
  struct maillon_int *m = l->premier, *res;
  if (m == NULL) {  return m; }
  --l->longueur;
  if (m->suivant == NULL) {
    l->premier = NULL;
    l->dernier = NULL;
    return m;
  }
  while (m->suivant->suivant != NULL) {
    m = m->suivant;
  }
  l->dernier = m;
  res = m->suivant;
  m->suivant = NULL;
  return res;
}

/** Libère l'espace mémoire occupé sur le tas par la liste et tous ses maillons */
void detruire_liste_int (struct liste_int **l) {
  if (*l != NULL) {
    while (!est_vide_liste_int(*l)) {
      struct maillon_int *m = extraire_maillon_debut_liste_int(*l);
      detruire_maillon_int(&m);
    }
    free(*l);
    *l = NULL;
  }
}
