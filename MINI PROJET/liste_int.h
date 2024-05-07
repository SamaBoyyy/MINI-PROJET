#ifndef _LISTE_INT_H
#define _LISTE_INT_H


struct maillon_int {
  int  valeur; /* valeur du maillon */
  struct maillon_int *suivant; /* adresse du maillon suivant */
};

struct liste_int {
  struct maillon_int *premier; /* adresse du premier maillon de la liste, NULL si la liste est vide */
  struct maillon_int *dernier; /* adresse du dernier maillon de la liste NULL si la liste est vide */
  int longueur; /* nombre de maillons dans la liste */
};

/* allocation sur le tas pour un maillon de valeur v */
/* et renvoi de l'adresse du maillon */
struct maillon_int *nouveau_maillon_int (int v);

/* libération de l'espace mémoire occupé par le maillon */
void detruire_maillon_int (struct maillon_int **m);

/* allocation sur le tas pour une liste vide */
/* et renvoi de l'adresse de la liste */
struct liste_int *nouvelle_liste_int();

/* test de la vacuité de la liste d'adresse l */
int est_vide_liste_int(const struct liste_int *l);

/* renvoi du nombre de maillons dans la liste */
int longueur_liste_int(const struct liste_int *l);

/* affichage des valeurs de la liste d'adresse l */
void afficher_liste_int(const struct liste_int *l);

/* insertion du maillon d'adresse m au début de la liste d'adresse l */
void ajouter_maillon_debut_liste_int(struct liste_int *l, struct maillon_int *m);

/* insertion d'un maillon d'adresse m à la fin de la liste d'adresse l */
void ajouter_maillon_fin_liste_int(struct liste_int *l, struct maillon_int *m);

/* extraction du premier maillon de la liste d'adresse l */
/* et renvoi de l'adresse du maillon extrait */
struct maillon_int *extraire_maillon_debut_liste_int(struct liste_int *l);

/* extraction du dernier maillon de la liste d'adresse l */
/* et renvoi de l'adresse du maillon extrait */
struct maillon_int *extraire_maillon_fin_liste_int(struct liste_int *l);

/* libération de l'espace occupé par la liste et tous ses maillons */
void detruire_liste_int (struct liste_int **l);

#endif
