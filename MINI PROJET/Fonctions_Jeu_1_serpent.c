#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "grille.h"
#include "serpent.h"
#include "Fonctions_Jeu.h"

void jouer_jeu_serpent( int delai, grille *g,  serpent *s){
    
  int ch, ch_dern;
  int i=0;

  /* Initialisation de ncurses et du clavier(4 lignes)*/
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();


  halfdelay(1);  /* Temps d'exécution max de getch à 1/10eme de seconde */

  do{
  
    ch = getch();
    
    i++;  /* Compteur pour se rendre compte que "le temps passe" */

    if (ch==-1){  /* Si aucune touche utilisee, getch renvoie -1 */
       /* Comme aucune touche n'a ete utilisee
          le programme peut faire autre chose */
       printf("%d\33[1E",i);  /* Par exemple : afficher un compteur */
    } 
    else{
       /* Ici une touche a ete utilisee, getch a renvoyee son code
          le programme peut repondre a l'utilisateur du clavier*/
      ch_dern=ch; /* Par exemple ici, on sauvegarde la dernière touche utilisee pour l'afficher*/     
    
    }
    
    /* A partir d'ici, les actions sont effectuees que l'utilisateur ait appuye ou non sur une touche) */
    
    printf("\33[2J");
    printf("\33[H");
 
   

   switch(ch_dern) {  
      case KEY_UP:   /* Ces constantes sont dans ncurses pour correspondre aux codes de touches */
         Grille_vider(g);
         Grille_tirage_fruit(g);
         Grille_remplir(g,s);
         printf("\33[2J");
         printf("\33[1E");         
         Grille_redessiner(g);

           /*i=0;
           if(s->x == g->n) {
                printf("Vous avez perdu\n");
                exit(EXIT_FAILURE);
           } 
           s->x++;
           Grille_remplir(g,s);
           Grille_redessiner(g);*/
         break;

      case KEY_DOWN: 
         printf("sx = %d ; sy = %d",s->x,s->y);
         
         printf("\33[1E");   
           /*
           if(s->x == 0) {
                printf("Vous avez perdu\n");
                exit(EXIT_FAILURE);
           } 
           s->x--;
           Grille_remplir(g,s);
           Grille_redessiner(g);*/
           break;
        case KEY_LEFT: 
           

           /*if(s->y == 0) {
                printf("Vous avez perdu\n");
                exit(EXIT_FAILURE);
           } 
           s->y--;
           Grille_remplir(g,s);
           Grille_redessiner(g);*/
           break; 
        case KEY_RIGHT: 
           
          /* 
           if(s->y == g->m) {
                printf("Vous avez perdu\n");
                exit(EXIT_FAILURE);
           } 
           s->y++;
           Grille_remplir(g,s);
           Grille_redessiner(g); */
           break;

        default:
           Grille_redessiner(g);
           //printf("\33[2J");
           break;
      }
      
   fflush(stdout);  /* Force l'affichage complet des commandes precedentes */
   
  } while (ch!= '#');

    
  endwin(); /* Doit obligatoirement etre mis en fin de programme pour remettre le terminal en etat */

}