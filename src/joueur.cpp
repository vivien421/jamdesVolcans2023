#include "joueur.hpp"
#include <iostream>

void Joueur::debugAfficher() const {
	std::printf("ressource [%d], vie [%d], \n\tunités :\n", ressource, getVie());
	for(auto u: unites) {
		u.debugAfficher();
	}
	std::puts("\tbatiments : ");
	for(auto b: batiments) {
		b.debugAfficher();
	}
	std::printf("\n");
}
