#include "unite.hpp"
#include <iostream>

void Unite::debugAfficher() const {
	std::printf("prix [%d] degat unite [%d] degat batiment [%d] pv [%d] vitesse d'attaque [%d] deplacement [%d], position [%d], taille [%d]\n", prix, degatUnite, degatBatiment, pv, vitesseAtk, deplacement, position, taille); 
}
