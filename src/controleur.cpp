#include "controleur.hpp"
#include "collisionEngine.hpp"
#include "stats.hpp"

bool Controleur::creerUnite(bool demon, int type) {
    bool creation = false;

    if (demon)
    {
        Unite unit = Unite(20, 80, 0.05, 1, 1, 1, 0.02, 1, demon, type);
        
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
        Unite unit = Unite(20, 80, 0.05, 1, 1, 1, 0.02, 1, !demon, type);
        
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