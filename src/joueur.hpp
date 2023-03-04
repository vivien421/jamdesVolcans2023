#pragma once
#include <vector>
#include "batiment.hpp"
#include "unite.hpp"

struct Joueur {
	int ressource = 10;
	int vie = 1;
	std::vector<Unite> unites;
	std::vector<Batiment> batiments;
	

	void debugAfficher() const;
};
