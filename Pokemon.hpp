#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "Pokedex.hpp"
#include "IVs.hpp"
#include "EVs.hpp"

class Pokemon
{
    const ID dex;
    const Name name;
    const uint8_t level;
    const IVs ivs;
    EVs evs;
    Stats stats;

public:
    Pokemon(ID dex, Name name, uint8_t level) : dex(dex), name(name), level(level), stats(Stats(Pokedex::getInstance()->getPokemonBaseStats(dex), ivs, evs, level)) {}
    Pokemon(ID dex, uint8_t level) : Pokemon(dex, Pokedex::getInstance()->getPokemonName(dex), level) {}
};

#endif