#include "batiment.hpp"
#include <iostream>

Batiment::Batiment(int new_prix, int new_pv, float new_position, int new_taille, std::string new_type):
		Entite(new_prix, new_pv, new_position, new_taille), type(new_type)
{}

void Batiment::debugAfficher() const {
	std::printf("Batiment: prix [%d] pv [%d], position [%f], taille [%f], type [%s]\n", prix, pv, position, taille, type.c_str()); 
}
