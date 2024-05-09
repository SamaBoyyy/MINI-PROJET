#ifndef _LISTE_INT_H
#define _LISTE_INT_H
#define item int

typedef struct section_s {
  item  taille; /* Taille de la section */
  char *couleur; /* Couleur section */
  struct section_s *suivant; /* adresse du maillon suivant */
}Section;

typedef struct liste_section_s {
  Section *premier; /* adresse du premier maillon de la liste, NULL si la liste est vide */
  Section *dernier; /* adresse du dernier maillon de la liste NULL si la liste est vide */
  int longueur; /* nombre de maillons dans la liste */
}liste_section;

/* allocation sur le tas pour un maillon de valeur v */
/* et renvoi de l'adresse du maillon */
Section *nouvelle_Section (int v);

/* libération de l'espace mémoire occupé par le maillon */
void detruire_Section (Section **m);

/* allocation sur le tas pour une liste vide */
/* et renvoi de l'adresse de la liste */
liste_section *nouvelle_liste_section();

/* test de la vacuité de la liste d'adresse l */
int est_vide_liste_section(const liste_section *l);

/* renvoi du nombre de maillons dans la liste */
int longueur_liste_section(const liste_section *l);

/* affichage des valeurs de la liste d'adresse l */
void afficher_liste_couleur(const liste_section *l);

/* insertion du maillon d'adresse m au début de la liste d'adresse l */
void ajouter_maillon_debut_liste_section(liste_section *l, Section *m);

/* insertion d'un maillon d'adresse m à la fin de la liste d'adresse l */
void ajouter_maillon_fin_liste_section(liste_section *l, Section *m);

/* extraction du premier maillon de la liste d'adresse l */
/* et renvoi de l'adresse du maillon extrait */
Section *extraire_maillon_debut_liste_section(liste_section *l);

/* extraction du dernier maillon de la liste d'adresse l */
/* et renvoi de l'adresse du maillon extrait */
Section *extraire_maillon_fin_liste_section(liste_section *l);

/* libération de l'espace occupé par la liste et tous ses maillons */
void detruire_liste_section (liste_section **l);

#endif
