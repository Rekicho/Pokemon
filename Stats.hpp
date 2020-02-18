#ifndef STATS_HPP
#define STATS_HPP

#include <stdint.h>
#include <cmath>
#include "IVs.hpp"
#include "EVs.hpp"

class Stats
{
    uint16_t HP;
    uint16_t Attack;
    uint16_t Defense;
    uint16_t Speed;
    uint16_t Special;

public:
    Stats(uint16_t HP, uint16_t Attack, uint16_t Defense, uint16_t Speed, uint16_t Special) : HP(HP), Attack(Attack), Defense(Defense), Speed(Speed), Special(Special) {}
    Stats(Stats base, IVs ivs, EVs evs, uint8_t level)
    {
        calculateStats(base, ivs, evs, level);
    }

    const uint16_t getHP()
    {
        return HP;
    }
    const uint16_t getAttack()
    {
        return Attack;
    }
    const uint16_t getDefense()
    {
        return Defense;
    }
    const uint16_t getSpeed()
    {
        return Speed;
    }
    const uint16_t getSpecial()
    {
        return Special;
    }

    void calculateStats(Stats base, IVs ivs, EVs evs, uint8_t level)
    {
        HP = calculateHP(base.getHP(), ivs.getHP(), evs.getHP(), level);
        Attack = calculateStat(base.getAttack(), ivs.getAttack(), evs.getAttack(), level);
        Defense = calculateStat(base.getDefense(), ivs.getDefense(), evs.getDefense(), level);
        Speed = calculateStat(base.getSpeed(), ivs.getSpeed(), evs.getSpeed(), level);
        Special = calculateStat(base.getSpecial(), ivs.getSpecial(), evs.getSpecial(), level);
    }

    uint16_t calculateHP(uint16_t base, uint16_t iv, uint16_t ev, uint16_t level)
    {
        return floor((((base + iv) * 2 + floor(ceil(sqrt(ev)) / 4)) * level) / 100) + level + 10;
    }

    uint16_t calculateStat(uint16_t base, uint16_t iv, uint16_t ev, uint16_t level)
    {
        return floor((((base + iv) * 2 + floor(ceil(sqrt(ev)) / 4)) * level) / 100) + 5;
    }
};

#endif