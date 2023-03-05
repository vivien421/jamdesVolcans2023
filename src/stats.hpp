#ifndef STATS_HPP
#define STATS_HPP

typedef struct statsUnites {
	int type;
	int prix;
	int pv;
	int taille;
	int degatUnite;
	int degatBatiment;
	int vitesseAtk;
	int deplacement;
	int portee;
} statsUnites_t;

statsUnites_t tabStatsUnites[] =
{
	statsUnites_t {1, 10, 30, 1, 10, 15, 2, 2, 1},
	statsUnites_t {2, 15, 15, 1, 10, 5, 3, 3, 1}
};

#endif