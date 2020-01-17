#ifndef TYPE_HPP
#define TYPE_HPP

class Type
{
public:
    static const int NORMAL = 0;
    static const int FIRE = 1;
    static const int WATER = 2;
    static const int ELECTRIC = 3;
    static const int GRASS = 4;
    static const int ICE = 5;
    static const int FIGHTING = 6;
    static const int POISON = 7;
    static const int GROUND = 8;
    static const int FLYING = 9;
    static const int PSYCHIC = 10;
    static const int BUG = 11;
    static const int ROCK = 12;
    static const int GHOST = 13;
    static const int DRAGON = 14;
    static constexpr int EFFECTIVENESS[15][15] =
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
};

#endif