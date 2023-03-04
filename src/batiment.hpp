#pragma once

#include <string>
#include "entite.hpp"

struct Batiment : Entite {
	std::string type;

	virtual ~Batiment() {};

	void debugAfficher() const override;
};
