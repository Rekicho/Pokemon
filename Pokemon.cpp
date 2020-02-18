#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Player.hpp"

static const unsigned int windowWidth = 640;
static const unsigned int windowHeigth = 640;

sf::Texture grassTexture;
sf::Sprite grassSprite;

void load()
{
    grassTexture.loadFromFile("../images/grass.png");
    grassSprite.setTexture(grassTexture);
}

void randomEncounter()
{
    if (rand() % 10 < 1)
    {
        if (rand() % 20 < 9)
        {
            std::cout << "Rattata" << std::endl;
        }

        else
            std::cout << "Pidgey" << std::endl;
    }
}

void draw(sf::RenderWindow &window)
{
    // sf::Vector2u dimensions = grassTexture.getSize();

    // for (int j = 0; j <= windowHeigth - dimensions.y; j += dimensions.y)
    //     for (int i = 0; i <= windowWidth - dimensions.x; i += dimensions.x)
    //     {
    //         grassSprite.setPosition(sf::Vector2f((float)i, (float)j));
    //         window.draw(grassSprite);
    //     }
}

int main()
{
    srand(time(NULL));
    load();
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeigth), "Pokemon");
    Player player("Red");
    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                player.handleInput(event.key.code);
                break;
            }
        }

        player.update(dt);

        window.clear(sf::Color::Black);
        draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}