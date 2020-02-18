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
    sf::Texture walkingTextures[3];
    sf::Sprite sprite;
    sf::Vector2f velocity;
    sf::Vector2f position;
    Orientation orientation;
    bool moving = false;
    float movingTime = 0;
    const float timePerStep = 0.5;
    const float timeStopped = 0.1;

public:
    sf::Vector2f getPosition()
    {
        return position;
    }

    Player(Name name) : name(name), textures{sf::Texture(), sf::Texture(), sf::Texture()}, walkingTextures{sf::Texture(), sf::Texture(), sf::Texture()}, orientation(Orientation::DOWN)
    {
        sf::Image playerImage;
        playerImage.loadFromFile("../images/people.png");
        playerImage.createMaskFromColor(sf::Color(0, 255, 0));

        textures[0].loadFromImage(playerImage, sf::IntRect(112, 269, 16, 16));
        textures[1].loadFromImage(playerImage, sf::IntRect(131, 269, 16, 16));
        textures[2].loadFromImage(playerImage, sf::IntRect(6, 288, 16, 16));

        walkingTextures[0].loadFromImage(playerImage, sf::IntRect(22, 288, 16, 16));
        walkingTextures[1].loadFromImage(playerImage, sf::IntRect(38, 288, 16, 16));
        walkingTextures[2].loadFromImage(playerImage, sf::IntRect(54, 288, 16, 16));

        position = sf::Vector2f(136.f, 40.f);
        sprite.setOrigin(8.f, 8.f);
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

        if (velocity != sf::Vector2f(0.f, 0.f))
        {
            switch (orientation)
            {
            case Orientation::UP:
                sprite.setTexture(walkingTextures[1]);
                break;
            case Orientation::LEFT:
                sprite.setTexture(walkingTextures[2]);
                break;
            case Orientation::DOWN:
                sprite.setTexture(walkingTextures[0]);
                break;
            case Orientation::RIGHT:
                sprite.setTexture(walkingTextures[2]);
                break;
            }
        }

        sprite.setPosition(position);
        window.draw(sprite);
    }

    void
    handleInput(sf::Keyboard::Key key)
    {
        if (moving || (movingTime >= timePerStep && movingTime < (timePerStep + timeStopped)))
            return;

        switch (key)
        {
        case sf::Keyboard::W:
            moving = orientation == Orientation::UP;
            velocity = moving ? sf::Vector2f(0, -16 / timePerStep) : velocity = sf::Vector2f(0, 0);
            orientation = Orientation::UP;
            break;
        case sf::Keyboard::A:
            moving = orientation == Orientation::LEFT;
            velocity = moving ? sf::Vector2f(-16 / timePerStep, 0) : velocity = sf::Vector2f(0, 0);
            orientation = Orientation::LEFT;
            break;
        case sf::Keyboard::S:
            moving = orientation == Orientation::DOWN;
            velocity = moving ? sf::Vector2f(0, 16 / timePerStep) : velocity = sf::Vector2f(0, 0);
            orientation = Orientation::DOWN;
            break;
        case sf::Keyboard::D:
            moving = orientation == Orientation::RIGHT;
            velocity = moving ? sf::Vector2f(16 / timePerStep, 0) : velocity = sf::Vector2f(0, 0);
            orientation = Orientation::RIGHT;
            break;
        }

        movingTime = moving ? 0 : movingTime;
    }

    void move(float x, float y, sf::View &view)
    {
        position.x += x;
        position.y += y;
        view.move(x,y);
    }

    void stop()
    {
        velocity = sf::Vector2f(0.f, 0.f);
        moving = false;
    }

    void update(sf::Time time, sf::View &view)
    {
        if (!moving)
        {
            if (movingTime > timePerStep && movingTime <= (timePerStep + timeStopped))
                movingTime += time.asSeconds();

            return;
        }

        float oldTime = movingTime;
        movingTime += time.asSeconds();

        if (movingTime < timePerStep)
            move(velocity.x * time.asSeconds(), velocity.y * time.asSeconds(), view);

        else if (movingTime >= timePerStep && moving)
        {
            move(velocity.x * (timePerStep - oldTime), velocity.y * (timePerStep - oldTime), view);
            stop();
        }
    }
};

#endif