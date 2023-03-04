#pragma once

#include "entite.hpp"

struct Unite : Entite {
	int id;
	int type;
	int degatUnite = 0;
	int degatBatiment = 0;
	int vitesseAtk = 1;
	int deplacement = 1;
	int porte = 1;

	static int compteur;

	Unite(int);
	virtual ~Unite() {};

	void debugAfficher() const override;
};
