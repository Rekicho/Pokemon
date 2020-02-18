#ifndef MAP_HPP
#define MAP_HPP

#include <stdint.h>
#include <fstream>
#include <string>
#include <math.h>

class Map
{
    static const uint16_t FREE = 0;
    static const uint16_t BLOCKED = 1;
    static const uint16_t mapWidth = 18;
    static const uint16_t mapHeight = 36;

    uint16_t map[mapHeight][mapWidth];

public:
    Map()
    {
        std::ifstream file("../res/route1.txt");
        std::string temp;
        int i = 0;

        while (std::getline(file, temp))
        {
            for(int j = 0; j < temp.length(); j++)
            {
                if(temp[j] == 'B')
                    map[i][j] = BLOCKED;

                else map[i][j] = FREE;
            }

            i++;
        }

        file.close();
    }

    bool canMove(float x, float y, float dx, float dy)
    {
        int16_t currentX = ((round(x) - 8) / 16);
        int16_t currentY = ((round(y) - 8) / 16);

        if (dx < 0)
            currentX--;

        else if (dx > 0)
            currentX++;

        if (dy < 0)
            currentY--;

        else if (dy > 0)
            currentY++;

        return currentX >= 0 && currentX < mapWidth && currentY >= 0 && currentY < mapHeight && map[currentY][currentX] == FREE;
    }
};

#endif