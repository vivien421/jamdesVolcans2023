#ifndef STATS_HPP
#define STATS_HPP

typedef struct statsUnites {
	int type;
	int prix;
	int pv;
	float taille;
	int degatUnite;
	int degatBatiment;
	int vitesseAtk;
	float deplacement;
	int portee;
} statsUnites_t;

statsUnites_t tabStatsUnites[] =
{
	statsUnites_t {0, 10, 30, 0.02, 10, 15, 2, 0.05, 2},
	statsUnites_t {1, 15, 15, 0.05, 10, 5, 3, 0.01, 1},
	statsUnites_t {2, 15, 15, 0.03, 10, 5, 3, 0.02, 1},
	statsUnites_t {3, 15, 15, 0.03, 10, 5, 3, 0.02, 1},
	statsUnites_t {4, 15, 15, 0.03, 10, 5, 3, 0.02, 1},
	statsUnites_t {5, 15, 15, 0.03, 10, 5, 3, 0.02, 1},
	statsUnites_t {6, 15, 15, 0.03, 10, 5, 3, 0.02, 1}
};

#endif