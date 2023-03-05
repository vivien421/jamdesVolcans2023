#include "controleur.hpp"
#include "collisionEngine.hpp"
#include "stats.hpp"

void Controleur::updateOmbre(float dt) {
	int gainPassif = 30;
	j1.ressource += static_cast<int>(gainPassif * dt);
}

Controleur::Controleur() {
	j1.base = Batiment{0, 500, 0, 0.05, "base"};
	j1.batiments.push_back(j1.base);
	j2.base = Batiment{0, 500, 1, 0.05, "base"};
	j2.batiments.push_back(j2.base);
}

bool Controleur::creerUnite(bool demon, int type) {
	bool creation = false;
	statsUnites_t stats = tabStatsUnites[type];

	if (demon)
	{
		Unite unit = Unite(stats.prix, stats.pv, stats.taille, stats.degatUnite, stats.degatBatiment, stats.vitesseAtk, stats.deplacement, stats.portee, demon, type);
		
		if (j1.unites.empty() || (!j1.unites.empty() && !CollisionEngine::Collision(unit, j1.unites.back())))
		{
			j1.unites.push_back(std::move(unit));
			creation = true;

				std::cout << "Nouvelle unite crée" << std::endl;
				unit.debugAfficher();
		}
	}
	else
	{
		Unite unit = Unite(stats.prix, stats.pv, stats.taille, stats.degatUnite, stats.degatBatiment, stats.vitesseAtk, stats.deplacement, stats.portee, !demon, type);
		
		if (j2.unites.empty() || (!j2.unites.empty() && !CollisionEngine::Collision(unit, j2.unites.back())))
		{
			j2.unites.push_back(std::move(unit));
			creation = true;

			std::cout << "Nouvelle unite crée" << std::endl;
			unit.debugAfficher();
		}
	}

	return creation;
}

void Controleur::gestionAttaques() {
	for (Unite& u : j1.unites)
	{
		if (!j2.unites.empty() && CollisionEngine::PeutAttaquer(u, j2.unites[0]))
		{
			j2.unites[0].pv -= u.degatUnite;
		}
		else
		{
			for (Batiment& b : j2.batiments)
			{
				if (CollisionEngine::PeutAttaquer(u, b))
					b.pv -= u.degatBatiment;
			}
		}
	}

	for (Unite& u : j2.unites)
	{
		if (!j1.unites.empty() && CollisionEngine::PeutAttaquer(u, j1.unites[0]))
		{
			j1.unites[0].pv -= u.degatUnite;
		}
		else
		{
			for (Batiment& b : j1.batiments)
			{
				if (CollisionEngine::PeutAttaquer(u, b))
					b.pv -= u.degatBatiment;
			}
		}
	}
}

void Controleur::actualisation() {
	//deplacerUnites(j1, j2);
	gestionAttaques();
	updateOmbre(1);
}
