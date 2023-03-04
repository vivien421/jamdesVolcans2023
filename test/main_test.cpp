//Test des fonctionalités non graphiques

#include <iostream>
#include "main_test.hpp"
#include "entite.hpp"
#include "unite.hpp"
#include "batiment.hpp"

void Test_Entite()
{
    printf("[Entite par defaut - debugAfficher]");
    Entite e;
    e.debugAfficher();

    printf("[Entite par valeurs - debugAfficher]");
    Entite e2(10, 50, 3, 2);
    e2.debugAfficher();
}

void Test_Unite()
{
    
    printf("[Unite par defaut - debugAfficher]");
    Unite u;
    u.debugAfficher();


}

void Test_Batiment()
{
    
    printf("[Batiment par defaut: debugAfficher]");
    Batiment b;
    b.debugAfficher();
}