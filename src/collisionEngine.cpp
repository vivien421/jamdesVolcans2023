#include "collisionEngine.hpp"

bool CollisionEngine::Collision(Entite& e1, Entite& e2) {
    if (e1.collision && e2.collision)
    {
        if (e1.position < e2.position)
            return (e1.position + e1.taille) > e2.position;
        else
            return (e2.position + e2.taille) > e1.position;
    }
    else
        return false;
}

//On ajuste toujours e1 par rapport à e2
void CollisionEngine::AjusterPosition(Entite& e1, Entite& e2) {
    if (Collision(e1, e2))
    {
        if (e1.position < e2.position)
        {
            e1.position -= e2.position - (e1.position + (float)e1.taille);
        }
        else
        {
            e1.position += e1.position - (e2.position + (float)e2.taille);
        }
    }
}

bool CollisionEngine::PeutAttaquer(Unite& e1, Entite& e2) {
    if (e1.position < e2.position)
        return e2.position <= (e1.position + e1.taille + e1.porte);
    else
        return (e2.position + e2.taille) >= (e1.taille + e1.porte);
}