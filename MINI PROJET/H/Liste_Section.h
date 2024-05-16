#ifndef _LISTE_SECTION_H
#define _LISTE_SECTION_H
#define item int

typedef struct section_s {

  /// @brief Taille de la section.
  item  taille;

  /// @brief Couleur section.
  char *couleur;

  /// @brief Adresse du maillon suivant.
  struct section_s *suivant;
  
}Section;

typedef struct liste_section_s {

  /// @brief adresse du premier maillon de la liste, NULL si la liste est vide.
  Section *premier;

  /// @brief adresse du dernier maillon de la liste NULL si la liste est vide
  Section *dernier;

  /// @brief nombre de maillons dans la liste
  int longueur;

}liste_section;

/// @brief Allocation sur le tas pour un maillon de valeur v.
/// @returns Renvoi de l'adresse du maillon.
Section *nouvelle_Section (int v);

/// @brief libération de l'espace mémoire occupé par le maillon.
/// @returns Ne renvoie rien.
void detruire_Section (Section **m);

/// @brief Allocation sur le tas pour une liste vide.
/// @returns Renvoi de l'adresse de la liste.
liste_section *nouvelle_liste_section();

/// @brief test de la vacuité de la liste d'adresse l.
/// @returns Renvoie un bool, vrai ou faux.
int est_vide_liste_section(const liste_section *l);

/// @returns renvoi du nombre de maillons dans la liste.
int longueur_liste_section(const liste_section *l);

/// @brief affichage des valeurs de la liste d'adresse l.
/// @returns Ne renvoie rien.
void afficher_liste_couleur(const liste_section *l);

/// @brief insertion du maillon d'adresse m au début de la liste d'adresse l.
/// @returns Ne renvoie rien.
void ajouter_maillon_debut_liste_section(liste_section *l, Section *m);

/// @brief insertion d'un maillon d'adresse m à la fin de la liste d'adresse l.
/// @returns Ne renvoie rien.
void ajouter_section_fin_liste_section(liste_section *l, Section *m);

/// @brief extraction du premier maillon de la liste d'adresse l.
/// @returns et renvoi de l'adresse du maillon extrait.
Section *extraire_maillon_debut_liste_section(liste_section *l);

/// @brief  Extraction du dernier maillon de la liste d'adresse l.  
/// @returns Renvoi de l'adresse du maillon extrait.
Section *extraire_maillon_fin_liste_section(liste_section *l);

/// @brief libération de l'espace occupé par la liste et tous ses maillons.
/// @returns Ne renvoie rien.
void detruire_liste_section (liste_section **l);

#endif
