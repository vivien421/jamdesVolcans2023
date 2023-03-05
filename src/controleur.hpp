#pragma once
#include "joueur.hpp"
#include "gameLoop.hpp"

class Controleur {
	Joueur j1, j2;

	void actualisation();
	void creerUnite(Joueur joueur, int id);
};