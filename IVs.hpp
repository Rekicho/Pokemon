#ifndef IVS_HPP
#define IVS_HPP

#include <stdint.h>
#include <cstdlib>

class IVs
{
    const uint8_t Attack;
    const uint8_t Defense;
    const uint8_t Speed;
    const uint8_t Special;

public:
    IVs() : Attack(rand() % 16), Defense(rand() % 16), Speed(rand() % 16), Special(rand() % 16) {}
    uint8_t getHP()
    {
        return ((Attack % 2) * 8) + ((Defense % 2) * 4) + ((Speed % 2) * 2) + (Special % 2);
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