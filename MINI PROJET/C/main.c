#include <stdio.h>
#include <stdlib.h>
#include "../H/grille.h"
#include "../H/serpent.h"
#include "../H/Liste_Section.h"
#include <ncurses.h>
#include <string.h>
#include "../H/Fonctions_Jeu.h"

int main(int argc, char *argv[]){
    int win_value ;
    if( argc != 5) {
        printf("Usage : ./game unsigned unsigned unsigned unsigned\n ./game Longueur x | Largeueu y | vitesse du jeu | Nom du Jeu ?\n");
        return EXIT_FAILURE;
    }
    unsigned x, y, delai; // Dimensions de la grille
    x     = strtoul( argv[1], NULL, 10);
    y     = strtoul( argv[2], NULL, 10);
    delai = strtoul( argv[3], NULL, 10);
    

    printf("x = %d y = %d\n", x,y);
    serpent * s = creer_serpent();
    printf("%s\n",s->l_serpent->premier->couleur);
    grille * g = Grille_allouer(x,y);
    if (g == NULL)
    {
        printf("\33[91mMEMOIRE INSUFISANTE\n");
        return EXIT_FAILURE;
    }
    Grille_vider(g);
    Grille_tirage_fruit(g,s);
    Grille_remplir(g,s);
    //#Grille_redessiner(g);
    
    //detruire_liste_section(s->l_serpent);
    /*if( s !=  NULL){
        if (s->l_serpent != NULL ) free(s->l_serpent);
        free(s);
    }*/
    if ((strcmp(argv[4],"serpent")== 0)|| (strcmp(argv[4],"Serpent")== 0)|| (strcmp(argv[4],"SERPENT")== 0))
    {
            
        win_value = jouer_jeu_serpent(delai, g, s);
    }
    else
    {
        printf("JEU NON TROUVE\nJEU DISPONIBLE : serpent \n");
    }

    if (win_value==1){
        printf("YOU LOSE\n");   
    }

    Grille_desallouer(g);
    serpent_desallouer(s);
    
    return EXIT_SUCCESS;
}
