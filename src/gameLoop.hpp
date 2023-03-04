#pragma once
#include "joueur.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>

void deplacerUnites(Joueur &, Joueur &);
void ajouteUnite(Joueur &, std::unordered_map<int, sf::Sprite> &, Unite, std::array<sf::Texture, 7> &);
