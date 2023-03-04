#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    const int WIDTH = 1800;
    const int HEIGHT = 1000;

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

    //Charge la texture pour les cauchmars
    sf::Texture badSpiritTexture;
    if (!badSpiritTexture.loadFromFile("res/badSpirit.png"))
        return EXIT_FAILURE;
    sf::Sprite badSpirit(badSpiritTexture);
    // position
    badSpirit.setPosition(sf::Vector2f(0, 0)); // position absolue
    //badSpirit.move(sf::Vector2f(0, 0)); // décalage relatif à la position actuelle
    // scale
    badSpirit.setScale(sf::Vector2f(0.1*scale*(1.f), 0.1*scale*(1.f))); // facteurs d'échelle absolus
    //badSpirit.scale(sf::Vector2f(0.1f, 0.1f)); // facters d'échelle relatifs à l'échelle actuelle

    //Charge la texture pour les rêve
    sf::Texture goodSpiritTexture;
    if (!goodSpiritTexture.loadFromFile("res/goodSpirit.png"))
        return EXIT_FAILURE;
    sf::Sprite goodSpirit(goodSpiritTexture);
    // position
    goodSpirit.setPosition(sf::Vector2f(0, 0)); // position absolue
    // scale
    goodSpirit.setScale(sf::Vector2f(0.1*scale*(1.f), 0.1*scale*(1.f))); // facteurs d'échelle absolus

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
        badSpirit.setPosition(sf::Vector2f(15.36*(1.f), 85.56484*(1.f))); // position absolue
        goodSpirit.setPosition(sf::Vector2f(((float) WIDTH - 150.36)*(1.f), 85.56484*(1.f))); // position absolue
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(background);
        window.draw(badSpirit);
        window.draw(goodSpirit);
        
        // Draw the string
        window.display();
    }
    return EXIT_SUCCESS;
}