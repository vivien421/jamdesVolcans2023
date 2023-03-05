#include "controleur.hpp"
#include "stats.hpp"

void Controleur::creerUnite(bool demon, int type) {
    j1.unites.push_back(Unite(20, 80, 0.05, 1, 1, 1, 0.02, 1, demon, type));
}