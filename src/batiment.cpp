#include "batiment.hpp"
#include <iostream>

void Batiment::debugAfficher() const {
	std::printf("Batiment: prix [%d] pv [%d], position [%d], taille [%d], type [%s]\n", prix, pv, position, taille, type.c_str()); 
}
