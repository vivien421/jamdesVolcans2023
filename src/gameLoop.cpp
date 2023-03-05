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

float xPosition(int WIDTH, float position) {
	return ((WIDTH/2)+((0.4*(1+0.1*cos(6*M_PI*position)))*WIDTH)*cos(-M_PI*position+M_PI));
}

float yPosition(int HEIGHT, float position) {
	return ((3*HEIGHT/4)+(0.5*(1+0.1*cos(6*M_PI*position))*HEIGHT)*sin(M_PI*position-M_PI));
}