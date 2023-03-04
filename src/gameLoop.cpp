#include "gameLoop.hpp"

void deplacerUnites(Joueur &demon, Joueur &reveur) {
	float deltaT = 1.0/60.0;
	for(auto & u: demon.unites) {
		u.position = u.position + u.deplacement * deltaT;
	}
	for(auto & u: reveur.unites) {
		u.position = u.position + u.deplacement * deltaT;
	}
}
