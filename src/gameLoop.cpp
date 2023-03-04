#include "gameLoop.hpp"

void deplacerUnites(Joueur &joueur, Joueur &bot) {
	static float frontPosition[2];
	float position;
	float deltaT = 1/60.0;
	for(auto u: joueur.unites) {
		position = u.position + u.deplacement * deltaT;
		if(position + u.taille > frontPosition[1]) {
			position = frontPosition[1] - u.taille;
		}
		u.position = position;
		if(position > frontPosition[0]) {
			frontPosition[0] = position;
		}
	}
	for(auto u: bot.unites) {
		position = u.position + u.deplacement * deltaT;
		if(position + u.taille > frontPosition[0]) {
			position = frontPosition[0] - u.taille;
		}
		u.position = position;
		if(position > frontPosition[1]) {
			frontPosition[1] = position;
		}
	}
}
