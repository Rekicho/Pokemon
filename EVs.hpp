#ifndef EVS_HPP
#define EVS_HPP

#include <stdint.h>
#include <cstdlib>

class EVs
{
    uint16_t HP = 0;
    uint16_t Attack = 0;
    uint16_t Defense = 0;
    uint16_t Speed = 0;
    uint16_t Special = 0;

public:
    uint8_t getHP()
    {
        return HP;
    }
    uint8_t getAttack()
    {
        return Attack;
    }
    uint8_t getDefense()
    {
        return Defense;
    }
    uint8_t getSpeed()
    {
        return Speed;
    }
    uint8_t getSpecial()
    {
        return Special;
    }
};

#endif