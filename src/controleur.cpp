#include "controleur.hpp"

void Controleur::updateOmbre(float dt) {
	int gainPassif = 30;
	j1.ressource += static_cast<int>(gainPassif * dt);
}

void Controleur::actualisation(float dt) {
	updateOmbre(dt);
}
