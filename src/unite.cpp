#include "unite.hpp"
#include <iostream>

int Unite::compteur = 0;

Unite::Unite(int p_type){
	this->id = compteur;
	this->type = p_type;
	compteur++;
	std::cout << "Nouvelle unite crée" << std::endl;
}

void Unite::debugAfficher() const {
	std::printf("Unite: prix [%d] degat unite [%d] degat batiment [%d] pv [%d] vitesse d'attaque [%d] deplacement [%d], position [%f], taille [%d], portée [%d]\n", prix, degatUnite, degatBatiment, pv, vitesseAtk, deplacement, position, taille, porte); 
}
