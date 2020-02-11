#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Pokedex.hpp"
#include "Pokemon.hpp"
#include <vector>

class Player
{
    const Name name;
    std::vector<Pokemon> party;

public:
    Player(Name name) : name(name) {}
};

#endif