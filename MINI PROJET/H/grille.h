#ifndef GRILLE_H
#define GRILLE_H

#include "serpent.h"

/// @brief structure d'une grille: composé d'une matrice de chaine de charactere et de 2 entiers non signé n et m. 
typedef struct grille_s {
    unsigned n;
    unsigned m;
    char * **tab;
    coord fruit;
} grille;

/// @brief alloue de l'espace pour une grille. 
/// @returns Renvoie une grille allouée.
grille * Grille_allouer( unsigned n, unsigned m);

/// @brief Met les cases de la grille sur la couleur par défaut.
/// @returns Ne renvoie rien.
void Grille_vider( grille *g );

/// @brief Tire un fruit aleatoire.
/// @returns Ne renvoie rien.
void Grille_tirage_fruit( grille *g , serpent *s);

/// @brief Colories les cases où se trouve le serpent et fruit.
/// @returns Ne renvoie rien.
void Grille_remplir( grille *g, serpent *s );

/// @brief Colories les cases du serpent avec l'animation de sa queue et du fruit.
/// @returns Ne renvoie rien.
void Grille_remplir_bis(grille * g ,serpent * s);

/// @brief Désaloue la mémoire d'une grille.
/// @returns Ne renvoie rien.
void Grille_desallouer( grille *g );

/// @brief Affiche les cases d'une grille, le liseret autout le serpent et le fruit. 
/// @returns Ne renvoie rien.
void Grille_redessiner( grille *g);

/// @brief Enlève la couleurs d'une case et la remet à "defaut" pour la vider.
/// @returns Ne renvoie rien.
void vider_case(grille  * g , int x , int y);



#endif 
