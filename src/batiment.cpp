#include "batiment.hpp"
#include <iostream>

void Batiment::debugAfficher() const {
	std::printf("prix [%d] pv [%d], position [%d], taille [%d]\n", prix, pv, position, taille); 
}
