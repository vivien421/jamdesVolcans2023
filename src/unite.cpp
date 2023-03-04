#include "unite.hpp"
#include <iostream>

void Unite::debugAfficher() const {
	std::printf("Unite: prix [%d] degat unite [%d] degat batiment [%d] pv [%d] vitesse d'attaque [%d] deplacement [%d], position [%d], taille [%d], portée [%d]\n", prix, degatUnite, degatBatiment, pv, vitesseAtk, deplacement, position, taille, porte); 
}
