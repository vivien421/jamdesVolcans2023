#ifndef COLLISION_ENGINE_HPP
#define COLLISION_ENGINE_HPP

#include "entite.hpp"
#include "unite.hpp"

class CollisionEngine {
    public:
        //Indique s'il y a collisison entre les deux entités
        static bool Collision(Entite& e1, Entite& e2);

        //Corrige la position de l'entité 1 en cas de collision avec l'entité 2
        static void AjusterPosition(Entite& e1, Entite& e2);

        //Indique si l'unité 1 peut attaquer l'entité 2
        static bool PeutAttaquer(Unite& e1, Entite& e2);
};

#endif