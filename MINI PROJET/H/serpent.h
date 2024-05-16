#ifndef SERPENT_H
#define SERPENT_H
#include "Liste_Section.h"
//#include "grille.h"

/// @brief Structure d'une coordonnée.
typedef struct coord_s {
    unsigned x;
    unsigned y;
} coord;

/// @brief Enum de tous les directions.
typedef enum direction {
    Haut,
    Bas,
    Droite,
    Gauche
}direction;

/// @brief Structure d'un maillon mouvement.
typedef struct mouvement_s {
    coord * position;
    struct mouvement_s *suivant;
}mouvement;

/// @brief Liste chainé de (maillon)_mouvement composé de sa longueur, du premier (maillon)_mouvement et du (maillon)_dernier.
typedef struct liste_mouvement_s {
    mouvement *l_premier;
    mouvement *l_dernier;
    int longueur;
}liste_mouvement;

/// @brief Structure d'un serpent composé de la position de sa tête en coordonné x et y, d'une liste chainée de (maillon)_section l_serpent ,une autre de (maillon)_mouvement l_mouvement
/// @brief et d'une variable de type direction (enum des directions : Haut, Bas, Gauche droite).
typedef struct serpent_s{
    unsigned x;
    unsigned y;
    liste_section *l_serpent;
    liste_mouvement *l_mouvement ;
    direction dir ;  
}serpent;




/// @brief Créer une variable de type struct serpent_s et alloue ses champs ainsi que que mettre la position de la tête à 2.
/// @returns Renvoie un serpent alloué et initialisé.
serpent * creer_serpent();

/// @brief Desalloue un (struct serpent_s)_serpent.
/// @returns Ne renvoie rien.
void serpent_desallouer(serpent *s);

/// @brief Prend un nombre aléatoire entre 41 et 47 pour le placer à place du X ici : \33[Xm; Cela permet d'avoir une couleur pseudo-aléatoire et de l'imprimer en chaine de character.
/// @returns Renvoie l'indice entier X. 
int couleur_aleatoire();

/// @brief Fait grandir le serpent de une section, en prenant une couleur pseudo-aléatoire pour cette dite nouvelle section.
/// @returns Ne renvoie rien.
void grandir_serpent(serpent * s);

/// @brief Ajoute un (maillon)_mouvement à la fin d'une liste chainé (maillon)_mouvement.
/// @returns Ne renvoie rien. 
void grandir_mouvement(liste_mouvement *l, int taille);

/// @brief Ajoute un (maillon)_mouvement à la fin d'une liste chainé de (maillon)_mouvement.
/// @returns Ne renvoie rien. 
void ajouter_mouvement_fin_liste_mouvement(liste_mouvement *l, mouvement *m);

/// @brief Alloue et initialise un nouveau (maillon)_mouvement.
/// @returns Renvoie ce (maillon)_mouvement.
mouvement * nouveau_mouvement();


/// @returns Renvoie 0 si la liste est vide et 1 sinon.
int est_vide_liste_mouvement(const liste_mouvement *l);

/// @brief Ajoute un (maillon)_mouvement à une liste pour la taille indiqué.
/// @returns Ne renvoie rien.
void grandir_mouvement(liste_mouvement *l, int taille);

/// @brief modifie le mouvement d'un (maillon)_mouvement
/// @returns Ne renvoie rien.
void haut(mouvement *m_mv, int tmpx, int tmpy);

/// @brief modifie le mouvement d'un (maillon)_mouvement
/// @returns Ne renvoie rien.
void bas(mouvement *m_mv, int tmpx, int tmpy);

/// @brief modifie le mouvement d'un (maillon)_mouvement
/// @returns Ne renvoie rien.
void droite(mouvement *m_mv, int tmpx, int tmpy);

/// @brief modifie le mouvement d'un (maillon)_mouvement
/// @returns Ne renvoie rien.
void gauche(mouvement *m_mv, int tmpx, int tmpy);

#endif



