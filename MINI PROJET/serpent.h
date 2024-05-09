#ifndef SERPENT_H
#define SERPENT_H
#include "Liste_Section.h"

typedef struct serpent_s{
    unsigned x;
    unsigned y;
    liste_section *l_serpent;
}serpent;

serpent * creer_serpent();
//void serpent_desallouer(serpent *s);

#endif