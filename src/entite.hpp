#ifndef ENTITE_HPP
#define ENTITE_HPP

#include <iostream>

struct Entite {
<<<<<<< HEAD
    int prix = 0;
    int pv = 1;
    float position = 0;
    int taille = 1;
    bool collision = true;
=======
	int id;
	int prix = 0;
	int pv = 1;
	float position = 0;
	int taille = 1;
>>>>>>> 81766f9d00456237c651e05bb25518a546d0df36

	static int compteur;

	Entite() {};
	Entite(int new_prix, int new_pv, float new_position, int new_taille);
	virtual ~Entite() {};

	virtual void debugAfficher() const;
};

#endif
