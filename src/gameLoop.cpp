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

float xPosition(int WIDTH, float position) {
	return ((WIDTH/2)+((0.4*(1+0.1*cos(6*M_PI*position)))*WIDTH)*cos(-M_PI*position+M_PI));
}

float yPosition(int HEIGHT, float position) {
	return ((3*HEIGHT/4)+(0.5*(1+0.1*cos(6*M_PI*position))*HEIGHT)*sin(M_PI*position-M_PI));
}