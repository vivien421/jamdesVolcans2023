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

void ajouteUnite(Joueur &joueur, std::unordered_map<int, sf::Sprite> &unitesSprite, Unite unite, std::array<sf::Texture, 7> &spiritTextures)
{
	joueur.unites.push_back(unite);
	unitesSprite.insert({unite.id, sf::Sprite(spiritTextures[unite.type])});
}
