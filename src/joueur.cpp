#include "joueur.hpp"
#include <iostream>

void Joueur::debugAfficher() const {
	std::printf("ressource [%d], vie [%d], unités :\n", ressource, vie);
	for(auto u: unites) {
		u.debugAfficher();
	}
	std::puts("batiments : ");
	for(auto b: batiments) {
		b.debugAfficher();
	}
}
