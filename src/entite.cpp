#include <iostream>
#include "entite.hpp"

int Entite::compteur = 0;

Entite::Entite(int new_prix, int new_pv, float new_position, int new_taille):
	prix(new_prix), pv(new_pv), position(new_position), taille(new_taille) {
	this->id = compteur;
}

void Entite::debugAfficher() const {
    std::printf("Entite: prix [%d] pv [%d], position [%f], taille [%d]\n", prix, pv, position, taille); 
}
