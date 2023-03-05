#pragma once

#include <string>
#include "entite.hpp"

struct Batiment : Entite {
	std::string type = "default";

	Batiment() {};
	Batiment(int new_prix, int new_pv, float new_position, float new_taille, std::string new_type);
	virtual ~Batiment() {};

	void debugAfficher() const override;
};
