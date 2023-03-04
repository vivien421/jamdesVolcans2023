#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
#include <unordered_map>
#include "unite.hpp"
#include "joueur.hpp"
#include "batiment.hpp"
#include "gameLoop.hpp"
#include "../test/main_test.hpp"

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 400;

	//Tests unitaires
	Test_Entite();
	Test_Unite();
	Test_Batiment();
	Test_Joueur();
	Test_Deplacement();
	Test_Collisions();

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
	
	// Load the background sprite to display
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("../res/background.png"))
		return EXIT_FAILURE;
	sf::Sprite background(backgroundTexture);
	const float scale = ((float) WIDTH)/backgroundTexture.getSize().x;
	// position of background
	background.setPosition(sf::Vector2f(0, (((float)HEIGHT)-scale*backgroundTexture.getSize().y)/2)); // position absolue
	background.move(sf::Vector2f(0, 0)); // décalage relatif à la position actuelle
	// scale of background
	background.setScale(sf::Vector2f(scale*(1.f), scale*(1.f))); // facteurs d'échelle absolus
	background.scale(sf::Vector2f(1.f, 1.f)); // facters d'échelle relatifs à l'échelle actuelle

	//Chargement des textures pour les cauchmars et rêves
	std::array<sf::Texture, 7> spiritTextures;
	
	for (int i = 0; i < 7; i++)
	{
		spiritTextures[i] = sf::Texture();
		if (!spiritTextures[i].loadFromFile("../res/units/badSpirit"+std::to_string(i+1)+".png"))
			return EXIT_FAILURE;
		//couleur cauchemar = #815628; couleur rêve = #0d5163
	}

	// Load a music to play
	/*
	sf::Music music;
	if (!music.openFromFile("nice_music.ogg"))
		return EXIT_FAILURE;
	// Play the music
	music.play();
	*/

	// interface
	std::array<sf::Sprite, 7> spawnButtons;
	float buttonScale = 0.1 * scale;
	for(int i = 0; i < 7; ++i) {
		spawnButtons[i].setTexture(spiritTextures[i]);
		spawnButtons[i].setScale(sf::Vector2f(buttonScale * (1.f), 0.1*scale*(1.f))); // facteurs d'échelle absolus
		spawnButtons[i].setPosition(buttonScale * i * 1000.f, 0.0f);
	}

	// timer 60 fps
	double t = 0.0;
	double deltaT = 1.0/60.0;

	// initialisation du jeu
	Unite unite(3);
	Joueur demon, reveur;
	std::unordered_map<int, sf::Sprite> unitesSprite;

	ajouteUnite(demon, unitesSprite, unite, spiritTextures);

	// Start the game loop
	while (window.isOpen())
	{
		//=====================Traitement================	
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch( event.type ) {

				// Close window: exit
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed: 
				{
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(pos.x), static_cast<float>(pos.y));
					if (spawnButtons[0].getGlobalBounds().contains(mousePosF)) ajouteUnite(demon, unitesSprite, Unite(0), spiritTextures);
					else if (spawnButtons[1].getGlobalBounds().contains(mousePosF)) ajouteUnite(demon, unitesSprite, Unite(1), spiritTextures);
					else if (spawnButtons[2].getGlobalBounds().contains(mousePosF)) ajouteUnite(demon, unitesSprite, Unite(2), spiritTextures);
					else if (spawnButtons[3].getGlobalBounds().contains(mousePosF)) ajouteUnite(demon, unitesSprite, Unite(3), spiritTextures);
					else if (spawnButtons[4].getGlobalBounds().contains(mousePosF)) ajouteUnite(demon, unitesSprite, Unite(4), spiritTextures);
					else if (spawnButtons[5].getGlobalBounds().contains(mousePosF)) ajouteUnite(demon, unitesSprite, Unite(5), spiritTextures);
					else if (spawnButtons[6].getGlobalBounds().contains(mousePosF)) ajouteUnite(demon, unitesSprite, Unite(6), spiritTextures);
					break;
				}
			}
		}
		// Fin de la partie
		if(demon.base.pv <= 0) {
			std::puts("Perdu !");
			window.close();
		}
		if(reveur.base.pv <= 0) {
			std::puts("Perdu !");
			window.close();
		}

		//Update position
		deplacerUnites(demon, reveur);
		for(auto & u: demon.unites) {
			unitesSprite[u.id].setPosition(sf::Vector2f(u.position*(1.f), 100*(1.f)));
		}
		for(auto u: reveur.unites) {
			unitesSprite[u.id].setPosition(sf::Vector2f(u.position*(1.f), 100*(1.f)));
		}

		//=====================Affichage=================	
		// Clear screen
		window.clear();
		
		// Draw the sprite
		window.draw(background);
		for( const auto& [key, value] : unitesSprite)
			window.draw(value);
		for(auto b: spawnButtons)
	        	window.draw(b);
		
		
		// Draw the string
		window.display();

		t += deltaT;
	}
	return EXIT_SUCCESS;
}
