#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Pokedex.hpp"

class Pokemon
{
    const ID dex;
    const Name name;

public:
    Pokemon(ID dex, Name name) : dex(dex), name(name) {}
    Pokemon(ID dex): dex(dex), name(Pokedex::getInstance()->getPokemonName(dex)) {}
};

#endif