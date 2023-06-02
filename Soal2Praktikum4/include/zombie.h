/*
 * Zombie class
 *
 * You can add any member variables or functions you need to this class.
 * This class derives from the Entity class.
 */
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "entity.h"

class Zombie : public Entity
{
    protected :
        int attack;
        int defense;
        int radius;
        int lethality;
        int spawnDay;
        int transformDay;
    public :
        Zombie(coordinate, int, int, int, int, int);
        ~Zombie();
        int getRadius();
        int getLethality();
        int getSpawnDay();
        void setSpawnDay(int);
        int getTransformDay();
};

#endif