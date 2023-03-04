#pragma once

#include "entite.hpp"

struct Unite : Entite {
	int type;
	int degatUnite = 0;
	int degatBatiment = 0;
	int vitesseAtk = 1;
	int deplacement = 1;
	int porte = 1;

	Unite(int);
	Unite() {};
	Unite(int new_prix, int new_pv, int new_taille, int new_degatUnite, int new_degatBatiment,
		int new_vitesseAtk, int new_deplacement, int new_porte);
	virtual ~Unite() {};

	void debugAfficher() const override;
};
