#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
#include <unordered_map>
#include "unite.hpp"
#include "joueur.hpp"
#include "batiment.hpp"
#include "gameLoop.hpp"
#include "controleur.hpp"
#include "../test/main_test.hpp"

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 400;
	const float uniteScale = 0.1;

	//Tests unitaires
	//Test_Entite();
	//Test_Unite();
	//Test_Batiment();
	//Test_Joueur();
	//Test_Deplacement();
	//Test_Collisions();
	Test_Base();

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

	//Création des tailles des esprits
	std::array<float, 7> spiritSizes = {1.0, 1.0, 1.0, 1.5, 1.5, 2.0, 2.0};
	//Chargement des textures pour les cauchmars et rêves
	std::array<sf::Texture, 7> spiritTextures;
	
	for (int i = 0; i < 7; i++)
	{
		spiritTextures[i] = sf::Texture();
		if (!spiritTextures[i].loadFromFile("../res/units/badSpirit"+std::to_string(i+1)+".png"))
			return EXIT_FAILURE;
		//couleur cauchemar = #815628; couleur rêve = #0d5163
	}

	// chargement des textures pour les batiments
	std::array<sf::Texture, 6> buildingTextures;
	for (int i = 0; i < 5; i++)
	{
		buildingTextures[i] = sf::Texture();
		if (!buildingTextures[i].loadFromFile("../res/buildings/batiment"+std::to_string(i+1)+".png"))
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

	// timer 60 fps
	double t = 0.0;
	double deltaT = 1.0/60.0;

	// initialisation du jeu
	Controleur controleur;
	std::unordered_map<int, sf::Sprite> unitesSprite;

	// interface
	std::array<sf::Sprite, 7> spawnButtons;
	float buttonScale = 0.1 * scale;
	for(int i = 0; i < 7; ++i) {
		spawnButtons[i].setTexture(spiritTextures[i]);
		spawnButtons[i].setScale(sf::Vector2f(buttonScale * (1.f), 0.1*scale*(1.f))); // facteurs d'échelle absolus
		spawnButtons[i].setPosition(buttonScale * i * 1000.f, 0.0f);
	}

	std::array<sf::Sprite, 6> spawnBatiments;
	float batimentScale = 0.1 * scale;
	for(int i = 0; i < 6; ++i) {
		spawnBatiments[i].setTexture(buildingTextures[i]);
		spawnBatiments[i].setScale(sf::Vector2f(batimentScale * (1.f), batimentScale*(1.f))); // facteurs d'échelle absolus
		spawnBatiments[i].setPosition(batimentScale * i * 1000.f, 1500.0f * batimentScale);
	}

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
					int typeNewUnit;

					if (spawnButtons[0].getGlobalBounds().contains(mousePosF)) typeNewUnit=0;
					else if (spawnButtons[1].getGlobalBounds().contains(mousePosF)) typeNewUnit=1;
					else if (spawnButtons[2].getGlobalBounds().contains(mousePosF)) typeNewUnit=2;
					else if (spawnButtons[3].getGlobalBounds().contains(mousePosF)) typeNewUnit=3;
					else if (spawnButtons[4].getGlobalBounds().contains(mousePosF)) typeNewUnit=4;
					else if (spawnButtons[5].getGlobalBounds().contains(mousePosF)) typeNewUnit=5;
					else if (spawnButtons[6].getGlobalBounds().contains(mousePosF)) typeNewUnit=6;
					else break;

					// Ajout d'une unitée
					bool creation = controleur.creerUnite(true, typeNewUnit);
					if (creation)
					{
						unitesSprite.insert({controleur.getLastUnitJ1().id, sf::Sprite(spiritTextures[controleur.getLastUnitJ1().type])});
						unitesSprite[controleur.getLastUnitJ1().id].setScale(uniteScale*scale*1.f, uniteScale*scale*1.f);
						unitesSprite[controleur.getLastUnitJ1().id].setColor(sf::Color(80,80,20));
					}
					break;
				}
				default:
					break;
			}
		}
		// Fin de la partie
		if(controleur.j1.base.pv <= 0) {
			std::puts("Perdu !");
			window.close();
		}
		if(controleur.j2.base.pv <= 0) {
			std::puts("Perdu !");
			window.close();
		}

		//Update position et combat
		controleur.actualisation();

		for(auto & u: controleur.j1.unites) {
			unitesSprite[u.id].setPosition(sf::Vector2f(((WIDTH/2)+((0.4*(1+0.1*cos(6*M_PI*u.position)))*WIDTH)*cos(-M_PI*u.position+M_PI))*(1.f), ((3*HEIGHT/4)+(0.5*(1+0.1*cos(6*M_PI*u.position))*HEIGHT)*sin(M_PI*u.position-M_PI))*(1.f)));
			//std::cout<< u.position << "; " << ((WIDTH/2)+(0.4*WIDTH)*cos(-M_PI*u.position+M_PI)) << "; " << ((HEIGHT/4)+(0.5*HEIGHT)*sin(-M_PI*u.position+M_PI))<<std::endl;
		}
		for(auto u: controleur.j2.unites) {
			unitesSprite[u.id].setPosition(sf::Vector2f(((WIDTH/2)+((0.4*(1+0.1*cos(6*M_PI*u.position)))*WIDTH)*cos(-M_PI*u.position+M_PI))*(1.f), ((3*HEIGHT/4)+(0.5*(1+0.1*cos(6*M_PI*u.position))*HEIGHT)*sin(M_PI*u.position-M_PI))*(1.f)));
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
		for(auto b: spawnBatiments)
	        	window.draw(b);
		
		
		// Draw the string
		window.display();

		t += deltaT;
	}
	return EXIT_SUCCESS;
}
