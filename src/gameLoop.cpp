#include "gameLoop.hpp"
#include "collisionEngine.hpp"

void deplacerUnites(Joueur &demon, Joueur &reveur) {
	float deltaT = 1.0/60.0;
	Unite* nextUnit = nullptr;

	for(auto & u: demon.unites) {
		u.position = u.position + u.deplacement * deltaT;

		if (nextUnit == nullptr)
		{
			if (reveur.unites.size() > 0)
				CollisionEngine::AjusterPosition(u, reveur.unites[0]);
			if (reveur.batiments.size() > 0)
				CollisionEngine::AjusterPosition(u, reveur.batiments[0]);
		}
		else
		{
			CollisionEngine::AjusterPosition(u, *nextUnit);
		}
		nextUnit = &u;
	}
	nextUnit = nullptr;

	for(auto & u: reveur.unites) {
		u.position = u.position - u.deplacement * deltaT;

		if (nextUnit == nullptr)
		{
			if (demon.unites.size() > 0)
				CollisionEngine::AjusterPosition(u, demon.unites[0]);
			if (demon.batiments.size() > 0)
				CollisionEngine::AjusterPosition(u, demon.batiments[0]);
		}
		else
		{
			CollisionEngine::AjusterPosition(u, *nextUnit);
		}
		nextUnit = &u;
	}
}

void ajouteUnite(Joueur &joueur, std::unordered_map<int, sf::Sprite> &unitesSprite, Unite unite, std::array<sf::Texture, 7> &spiritTextures)
{
	joueur.unites.push_back(unite);
	unitesSprite.insert({unite.id, sf::Sprite(spiritTextures[unite.type])});
}
