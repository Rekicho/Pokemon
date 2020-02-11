#include <SFML/Graphics.hpp>

#include <iostream>

static const unsigned int windowWidth = 800;
static const unsigned int windowHeigth = 600;

sf::Texture grassTexture;
sf::Sprite grassSprite;

void load()
{
    grassTexture.loadFromFile("../images/grass.png");
    grassSprite.setTexture(grassTexture);
}

void draw(sf::RenderWindow &window)
{
    sf::Vector2u dimensions = grassTexture.getSize();
    
    for (int j = 0; j <= windowHeigth - dimensions.y; j += dimensions.y)
        for (int i = ((j / dimensions.y) % 2) * dimensions.x; i <= windowWidth - dimensions.x; i += 2 * dimensions.x)
        {
            grassSprite.setPosition(sf::Vector2f((float)i, (float)j));
            window.draw(grassSprite);
        }
}

int main()
{
    load();
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeigth), "Pokemon");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        draw(window);

        window.display();
    }

    return 0;
}