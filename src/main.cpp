#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
#include "unite.hpp"
#include "joueur.hpp"
#include "batiment.hpp"


int main()
{
	Batiment bat;
	Unite unite;
	Joueur joueur;
	joueur.batiments.push_back(bat);
	joueur.unites.push_back(unite);
	joueur.debugAfficher();
	const int WIDTH = 800;
	const int HEIGHT = 400;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML window");
	
	// Load the background sprite to display
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("res/background.png"))
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
	std::array<sf::Texture, 7> badSpiritTextures;
	
	std::array<sf::Sprite, 7> badSpirits;
	std::array<sf::Sprite, 7> goodSpirits;
	
	for (int i = 0; i < 7; i++)
	{
		badSpiritTextures[i] = sf::Texture();
		if (!badSpiritTextures[i].loadFromFile("res/units/badSpirit"+std::to_string(i+1)+".png"))
			return EXIT_FAILURE;
		//cauchemar ajouté
		badSpirits[i] = sf::Sprite(badSpiritTextures[i]);
		// position
		badSpirits[i].setPosition(sf::Vector2f(((float) i)*100.f, 0)); // position absolue
		// scale
		badSpirits[i].setScale(sf::Vector2f(0.1*scale*(1.f), 0.1*scale*(1.f))); // facteurs d'échelle absolus
		// color
		badSpirits[i].setColor(sf::Color(129, 86, 40));  //#815628

		//rêve ajouté
		goodSpirits[i] = sf::Sprite(badSpiritTextures[i]);
		// position
		goodSpirits[i].setPosition(sf::Vector2f(((float) i)*100.f, 250.f)); // position absolue
		// scale
		goodSpirits[i].setScale(sf::Vector2f(0.1*scale*(1.f), 0.1*scale*(1.f))); // facteurs d'échelle absolus
		// color
		goodSpirits[i].setColor(sf::Color(14, 81, 99));  //#0d5163
	}

	// Load a music to play
	/*
	sf::Music music;
	if (!music.openFromFile("nice_music.ogg"))
		return EXIT_FAILURE;
	// Play the music
	music.play();
	*/

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Update position
		badSpirits[0].setPosition(sf::Vector2f(15.36*(1.f), 85.56484*(1.f))); // position absolue
		
		// Clear screen
		window.clear();
		
		// Draw the sprite
		window.draw(background);
		for (int i = 0; i < 7; i++)
		{
			window.draw(badSpirits[i]);
			window.draw(goodSpirits[i]);
		}
		
		// Draw the string
		window.display();
	}
	return EXIT_SUCCESS;
}
