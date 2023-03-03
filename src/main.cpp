#include <SFML/Graphics.hpp>
#include "unite.hpp"
#include "joueur.hpp"
#include "batiment.hpp"

int main(void) {
	Batiment bat;
	Unite unite;
	Joueur joueur;
	joueur.batiments.push_back(bat);
	joueur.unites.push_back(unite);
	joueur.debugAfficher();
	return 0;
}

