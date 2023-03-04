//Test des fonctionalités non graphiques

#include <iostream>
#include "main_test.hpp"
#include "entite.hpp"
#include "unite.hpp"
#include "batiment.hpp"
#include "joueur.hpp"
#include "gameLoop.hpp"
#include "collisionEngine.hpp"

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
    Unite u2(20, 80, 3, 1, 1, 1, 1, 1, 1);
    u2.debugAfficher();

    printf("\n");
}

void Test_Batiment()
{
    printf("[Batiment par defaut - debugAfficher]\n");
    Batiment b;
    b.debugAfficher();

    printf("[Batiment par valeur - debugAfficher]\n");
    Batiment b2(100, 300, 10, 1, "mur");
    b2.debugAfficher();

    printf("\n");
}

void Test_Joueur()
{
    printf("[Joueur par défaut - debugAfficher]\n");
    Joueur j;
    j.debugAfficher();

    printf("[Joueur avec batiments et unités - debugAfficher]\n");
    j.unites.push_back(Unite());
    j.unites.push_back(Unite(20, 80, 3, 1, 1, 1, 1, 1, 1));
    j.batiments.push_back(Batiment(100, 300, 10, 1, "mur"));
    j.debugAfficher();
}

void Test_Deplacement()
{
    Joueur j1;
    Joueur j2;

    j1.unites.push_back(Unite(20, 80, 1, 1, 1, 1, 2, 1, 1));
    j2.unites.push_back(Unite(20, 80, 1, 1, 1, 1, 3, 1, 0));
    j2.batiments.push_back(Batiment(100, 300, 35, 5, "mur"));

    printf("[Déplacement des unités - 500 iteration]\n");
    printf("\tavant déplacement, j1\n");
    j1.debugAfficher();
    printf("\tavant déplacement, j2\n");
    j2.debugAfficher();
    for (int i  = 0; i < 500; i++) 
    {
        deplacerUnites(j1, j2);
    }
    printf("\taprès déplacement 1, j1\n");
    j1.debugAfficher();
    printf("\taprès déplacement 1, j2\n");
    j2.debugAfficher();

    j1.unites.push_back(Unite(10, 50, 3, 1, 1, 1, 1, 1 ,1));

    printf("[Déplacement des unités - 1000 iteration]\n");
    for (int i  = 0; i < 500; i++) 
    {
        deplacerUnites(j1, j2);
    }
    printf("\taprès déplacement 2, j1\n");
    j1.debugAfficher();
    printf("\taprès déplacement 2, j2\n");
    j2.debugAfficher();

    j1.unites.push_back(Unite(20, 80, 2, 1, 1, 1, 3, 1, 1));

    printf("[Déplacement des unités - 1500 iteration]\n");
    for (int i  = 0; i < 500; i++) 
    {
        deplacerUnites(j1, j2);
    }
    printf("\taprès déplacement 3, j1\n");
    j1.debugAfficher();
    printf("\taprès déplacement 3, j2\n");
    j2.debugAfficher();
}

void Test_Collisions() {
    printf("[CollisionEngine - pas de collisions]\n");
    Entite e1{0, 10, 0, 3};
    Entite e2{0, 10, 5, 1};
    printf("Collisison entre e1 et e2: %d\n", CollisionEngine::Collision(e1, e2));
    printf("Collisison entre e2 et e1: %d\n", CollisionEngine::Collision(e2, e1));
    printf("\n");
    
    printf("[CollisionEngine - collisisons]\n");
    Entite e3{0, 10, 0, 3};
    Entite e4{0, 10, 2.3, 1};
    printf("Collisison entre e4 et e3: %d\n", CollisionEngine::Collision(e3, e4));
    printf("Collisison entre e4 et e4: %d\n", CollisionEngine::Collision(e4, e3));
    printf("\n");

    printf("[CollisionEngine - correction de la collision]\n");
    CollisionEngine::AjusterPosition(e4, e3);
    printf("Collisison entre e4 et e3: %d\n", CollisionEngine::Collision(e3, e4));
    printf("Collisison entre e4 et e4: %d\n", CollisionEngine::Collision(e4, e3));
    printf("e3.position=%f\n", e3.position);
    printf("e4.position=%f\n", e4.position);
    printf("\n");
}