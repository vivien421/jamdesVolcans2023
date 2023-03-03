#pragma once
#include <vector>
#include "unite.hpp"

struct Joueur {
	int ressource = 10;
	int vie = 1;
	std::vector<Unite> unites;

	void debugAfficher();
};
