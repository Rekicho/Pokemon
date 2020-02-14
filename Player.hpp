#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Pokedex.hpp"
#include "Pokemon.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

enum Orientation
{
    UP,
    LEFT,
    RIGHT,
    DOWN
};

class Player
{
    const Name name;
    std::vector<Pokemon> party;
    sf::Texture textures[3];
    sf::Sprite sprite;
    sf::Vector2f position;
    Orientation orientation;

public:
    Player(Name name) : name(name), textures{sf::Texture(), sf::Texture(), sf::Texture()}, orientation(Orientation::UP)
    {
        sf::Image playerImage;
        playerImage.loadFromFile("../images/people.png");
        playerImage.createMaskFromColor(sf::Color(0, 255, 0));

        textures[0].loadFromImage(playerImage, sf::IntRect(112, 269, 16, 16));
        textures[1].loadFromImage(playerImage, sf::IntRect(131, 269, 16, 16));
        textures[2].loadFromImage(playerImage, sf::IntRect(6, 288, 16, 16));

        position = sf::Vector2f(8.f,8.f);
        sprite.setOrigin(8.f,8.f);
    }

    void draw(sf::RenderWindow &window)
    {
        switch (orientation)
        {
        case Orientation::UP:
            sprite.setScale(1.f, 1.f);
            sprite.setTexture(textures[1]);
            break;
        case Orientation::LEFT:
            sprite.setScale(1.f, 1.f);
            sprite.setTexture(textures[2]);
            break;
        case Orientation::DOWN:
            sprite.setScale(1.f, 1.f);
            sprite.setTexture(textures[0]);
            break;
        case Orientation::RIGHT:
            sprite.setScale(-1.f, 1.f);
            sprite.setTexture(textures[2]);
            break;
        }

        sprite.setPosition(position);
        window.draw(sprite);
    }

    void handleInput(sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::W:
            //move(sf::Vector2f(0, -16));
            orientation = Orientation::UP;
            break;
        case sf::Keyboard::A:
            //move(sf::Vector2f(-16, 0));
            orientation = Orientation::LEFT;
            break;
        case sf::Keyboard::S:
            //move(sf::Vector2f(0, 16));
            orientation = Orientation::DOWN;
            break;
        case sf::Keyboard::D:
            //move(sf::Vector2f(16, 0));
            orientation = Orientation::RIGHT;
            break;
        }
    }

    void move(sf::Vector2f move)
    {
        position += move;
    }
};

#endif