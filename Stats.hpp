#ifndef STATS_HPP
#define STATS_HPP

#include <stdint.h>

class Stats
{
    uint16_t HP;
    uint16_t Attack;
    uint16_t Defense;
    uint16_t Speed;
    uint16_t Special;

public:
    Stats(uint16_t HP, uint16_t Attack, uint16_t Defense, uint16_t Speed, uint16_t Special) : HP(HP), Attack(Attack), Defense(Defense), Speed(Speed), Special(Special) {}
};

#endif