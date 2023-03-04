#ifndef ENTITE_HPP
#define ENTITE_HPP

#include <iostream>

struct Entite {
    int prix = 0;
    int pv = 1;
    float position = 0;
    int taille = 1;

    virtual ~Entite() {};

    virtual void debugAfficher() const {
        std::printf("Entite: prix [%d] pv [%d], position [%f], taille [%d]\n", prix, pv, position, taille); 
    }
};

#endif