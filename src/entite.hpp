#ifndef ENTITE_HPP
#define ENTITE_HPP

#include <iostream>

struct Entite {
	int id;
	int prix = 0;
	int pv = 1;
	float position = 0;
	float taille = 0.05;
	bool collision = true;

	static int compteur;

	Entite() {};
	Entite(int new_prix, int new_pv, float new_position, float new_taille);
	virtual ~Entite() {};

	virtual void debugAfficher() const;
};

#endif
