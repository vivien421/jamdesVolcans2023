#pragma once
#include "joueur.hpp"
#include "gameLoop.hpp"

class Controleur {
	public:
		Joueur j1, j2;

		Controleur();

		void actualisation() {};
		bool creerUnite(bool demon, int type);
		Unite getLastUnitJ1() const { return j1.unites.back(); }
		Unite getLastUnitJ2() const { return j2.unites.back(); }
};