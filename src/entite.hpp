#ifndef ENTITE_HPP
#define ENTITE_HPP

#include <iostream>

struct Entite {
    int prix = 0;
    int pv = 1;
    float position = 0;
    int taille = 1;

    Entite() {};
    Entite(int new_prix, int new_pv, float new_position, int new_taille);
    virtual ~Entite() {};

    virtual void debugAfficher() const;
};

#endif