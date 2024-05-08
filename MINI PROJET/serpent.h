#ifndef SERPENT_H
#define SERPENT_H
#include "Liste_Section.h"


struct serpent_s{
    unsigned x;
    unsigned y;
    liste_section *l_serpent;
};

struct serpent_s * creer_serpent();

#endif