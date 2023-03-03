#include "joueur.hpp"
#include <iostream>

void Joueur::debugAfficher() {
	std::printf("ressource [%d], vie [%d], unités :\n", ressource, vie);
	for(auto i: unites) {
		i.debugAfficher();
	}
}
