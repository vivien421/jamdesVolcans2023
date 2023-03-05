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
	statsUnites_t {0, 5, 1000, 0.02,  5,  5, 2, 0.03, 2},
	statsUnites_t {1, 5, 1000, 0.02,  5,  3, 3, 0.06, 1},
	statsUnites_t {2, 5, 3000, 0.02,  3,  3, 3, 0.03, 1},
	statsUnites_t {3, 9, 2000, 0.03,  3, 10, 3, 0.02, 1},
	statsUnites_t {4, 9, 2000, 0.03, 12,  6, 3, 0.03, 1},
	statsUnites_t {5,20, 3500, 0.05, 12,  4, 3, 0.02, 1},
	statsUnites_t {6,20, 3500, 0.05,  4, 12, 3, 0.02, 1}
};

#endif