#pragma once
#include <vector>
#include "batiment.hpp"
#include "unite.hpp"

struct Joueur {
	int ressource = 10;
	std::vector<Unite> unites;
	std::vector<Batiment> batiments;
	Batiment base{0, 500, -5, 5, "base"};

	int getVie() const { return base.pv; }

	void debugAfficher() const;
};
