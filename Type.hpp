#ifndef TYPE_HPP
#define TYPE_HPP

enum class Type
{
    Bird = -1,
    Normal = 0,
    Fire = 1,
    Water = 2,
    Electric = 3,
    Grass = 4,
    Ice = 5,
    Fighting = 6,
    Poison = 7,
    Ground = 8,
    Flying = 9,
    Psychic = 10,
    Bug = 11,
    Rock = 12,
    Ghost = 13,
    Dragon = 14,
};

static constexpr double typeEffectiveness[15][15] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0, 1},
        {1, 0.5, 0.5, 1, 2, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5},
        {1, 2, 0.5, 1, 0.5, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5},
        {1, 1, 2, 0.5, 0.5, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5},
        {1, 0.5, 2, 1, 0.5, 1, 1, 0.5, 2, 0.5, 1, 0.5, 2, 1, 0.5},
        {1, 1, 0.5, 1, 2, 0.5, 1, 1, 2, 2, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 2, 0, 1},
        {1, 1, 1, 1, 2, 1, 1, 0.5, 0.5, 1, 1, 2, 0.5, 0.5, 1},
        {1, 2, 1, 2, 0.5, 1, 1, 2, 1, 0, 1, 0.5, 2, 1, 1},
        {1, 1, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1},
        {1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 1},
        {1, 0.5, 1, 1, 2, 1, 0.5, 2, 1, 0.5, 2, 1, 1, 0.5, 1},
        {1, 2, 1, 1, 1, 2, 0.5, 1, 0.5, 2, 1, 2, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}};

class PokemonType
{
    const Type type1;
    const Type type2;

public:
    PokemonType(Type type1, Type type2) : type1(type1), type2(type2) {}
    PokemonType(Type type) : type1(type), type2(Type::Bird) {}

    static double getAttackEffectiveness(Type attackType, PokemonType pokemonType)
    {
        if (pokemonType.type2 == Type::Bird)
            return typeEffectiveness[static_cast<std::underlying_type<Type>::type>(attackType)][static_cast<std::underlying_type<Type>::type>(pokemonType.type1)];

        return typeEffectiveness[static_cast<std::underlying_type<Type>::type>(attackType)][static_cast<std::underlying_type<Type>::type>(pokemonType.type1)] * typeEffectiveness[static_cast<std::underlying_type<Type>::type>(attackType)][static_cast<std::underlying_type<Type>::type>(pokemonType.type2)];
    }
};

#endif