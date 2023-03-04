//Test des fonctionalités non graphiques

#include <iostream>
#include "main_test.hpp"
#include "entite.hpp"
#include "unite.hpp"
#include "batiment.hpp"
#include "joueur.hpp"

void Test_Entite()
{
    printf("[Entite par defaut - debugAfficher]\n");
    Entite e;
    e.debugAfficher();

    printf("[Entite par valeurs - debugAfficher]\n");
    Entite e2(10, 50, 3, 2);
    e2.debugAfficher();

    printf("\n");
}

void Test_Unite()
{
    printf("[Unite par defaut - debugAfficher]\n");
    Unite u;
    u.debugAfficher();

    printf("[Unite par valeur - debugAfficher]\n");
    Unite u2(20, 80, 3, 1, 1, 1, 1, 1);
    u2.debugAfficher();

    printf("\n");
}

void Test_Batiment()
{
    printf("[Batiment par defaut: debugAfficher]\n");
    Batiment b;
    b.debugAfficher();

    printf("[Batiment par valeur: debugAfficher]\n");
    Batiment b2(100, 300, 10, 1, "mur");
    b2.debugAfficher();

    printf("\n");
}

void Test_Joueur()
{
    printf("[Joueur par défaut: debugAfficher]\n");
    Joueur j;
    j.debugAfficher();

    printf("[Joueur avec batiments et unités: debugAfficher]\n");
    j.unites.push_back(Unite());
    j.unites.push_back(Unite(20, 80, 3, 1, 1, 1, 1, 1));
    j.batiments.push_back(Batiment(100, 300, 10, 1, "mur"));
    j.debugAfficher();
}