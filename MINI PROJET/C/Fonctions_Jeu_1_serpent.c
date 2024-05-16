#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../H/grille.h"
#include "../H/serpent.h"
#include "../H/Fonctions_Jeu.h"

int jouer_jeu_serpent(int delai, grille *g, serpent *s)
{

   int ch, ch_dern;
   int i = 0;

   /* Initialisation de ncurses et du clavier(4 lignes)*/
   initscr();
   raw();
   keypad(stdscr, TRUE);
   noecho();

   halfdelay(delai); /* Temps d'exécution max de getch à 1/10eme de seconde */

   do
   {

      ch = getch();

      i++; /* Compteur pour se rendre compte que "le temps passe" */

      if (ch == -1)
      { /* Si aucune touche utilisee, getch renvoie -1 */
         /* Comme aucune touche n'a ete utilisee
            le programme peut faire autre chose */
         printf("%d\33[1E", i); /* Par exemple : afficher un compteur */
      }
      else
      {
         /* Ici une touche a ete utilisee, getch a renvoyee son code
            le programme peut repondre a l'utilisateur du clavier*/
         ch_dern = ch; /* Par exemple ici, on sauvegarde la dernière touche utilisee pour l'afficher*/
      }

      /* A partir d'ici, les actions sont effectuees que l'utilisateur ait appuye ou non sur une touche) */

      if (s->x < 0 || s->x > g->n - 1 || s->y < 0 || s->y > g->m - 1)
      {
         endwin();
         return 1;
      }
      else
      {
         Grille_vider(g);
         if (s->x == g->fruit.x && s->y == g->fruit.y)
         {
            Grille_tirage_fruit(g, s);
            grandir_serpent(s);
         }

         Grille_remplir_bis(g, s);

         Grille_redessiner(g);
      }

      switch (ch_dern)
      {
      case KEY_UP: /* Ces constantes sont dans ncurses pour correspondre aux codes de touches */
         s->x--;
         s->dir = Haut;
         Grille_remplir_bis(g, s);
         break;
      case KEY_DOWN:
         s->x++;
         s->dir = Bas;
         Grille_remplir_bis(g, s);
         break;
      case KEY_LEFT:
         s->y--;
         s->dir = Gauche;
         Grille_remplir_bis(g, s);
         break;
      case KEY_RIGHT:
         s->y++;
         s->dir = Droite;
         Grille_remplir_bis(g, s);
         break;
      default:
         break;
      }

      fflush(stdout); /* Force l'affichage complet des commandes precedentes */

   } while (ch != '#');

   endwin(); /* Doit obligatoirement etre mis en fin de programme pour remettre le terminal en etat */
   return 0;
}