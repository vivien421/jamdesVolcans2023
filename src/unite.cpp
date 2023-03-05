#include "unite.hpp"
#include <iostream>


Unite::Unite(int p_type){
	this->id = compteur;
	this->type = p_type;
	compteur++;
	std::cout << "Nouvelle unite crée" << std::endl;
}
Unite::Unite(int new_prix, int new_pv, float new_taille, int new_degatUnite, int new_degatBatiment,
			int new_vitesseAtk, float new_deplacement, int new_porte, bool joueur):
	Entite(new_prix, new_pv, joueur?0:1, new_taille), degatUnite(new_degatUnite), degatBatiment(new_degatBatiment),
	vitesseAtk(new_vitesseAtk), deplacement(new_deplacement), porte(new_porte)
{}

Unite::Unite(int new_prix, int new_pv, float new_taille, int new_degatUnite, int new_degatBatiment,
			int new_vitesseAtk, float new_deplacement, int new_porte, bool joueur, int p_type):
	Entite(new_prix, new_pv, joueur?0:1, new_taille), degatUnite(new_degatUnite), degatBatiment(new_degatBatiment),
	vitesseAtk(new_vitesseAtk), deplacement(new_deplacement), porte(new_porte)
{
	this->id = compteur;
	this->type = p_type;
	compteur++;
	std::cout << "Nouvelle unite crée" << std::endl;
}

void Unite::debugAfficher() const {
	std::printf("Unite: prix [%d] degat unite [%d] degat batiment [%d] pv [%d] vitesse d'attaque [%d] deplacement [%f], position [%f], taille [%f], portée [%d]\n", prix, degatUnite, degatBatiment, pv, vitesseAtk, deplacement, position, taille, porte); 
}
