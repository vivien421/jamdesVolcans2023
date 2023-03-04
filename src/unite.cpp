#include "unite.hpp"
#include <iostream>

int Unite::compteur = 0;

Unite::Unite(int p_type){
	this->id = compteur;
	this->type = p_type;
	compteur++;
	std::cout << "Nouvelle unite crée" << std::endl;
}
Unite::Unite(int new_prix, int new_pv, int new_taille, int new_degatUnite, int new_degatBatiment,
			int new_vitesseAtk, int new_deplacement, int new_porte, bool joueur):
	Entite(new_prix, new_pv, joueur?0:100, new_taille), degatUnite(new_degatUnite), degatBatiment(new_degatBatiment),
	vitesseAtk(new_vitesseAtk), deplacement(new_deplacement), porte(new_porte)
{}

void Unite::debugAfficher() const {
	std::printf("Unite: prix [%d] degat unite [%d] degat batiment [%d] pv [%d] vitesse d'attaque [%d] deplacement [%d], position [%f], taille [%d], portée [%d]\n", prix, degatUnite, degatBatiment, pv, vitesseAtk, deplacement, position, taille, porte); 
}
