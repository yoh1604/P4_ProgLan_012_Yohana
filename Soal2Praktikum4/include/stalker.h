/*
 * Stalker class
 *
 * You can add any member variables or functions you need to this class.
 * This class derives from the Zombie class.
 * Stalker Stats:
 * - Attack: 200-300
 * - Defense: 200-300
 * - Lethality: 0.2
 * - Radius: 12
 */
#ifndef STALKER_H
#define STALKER_H

#include "zombie.h"

class Stalker : public Zombie
{
    public :
        Stalker(coordinate);
};

#endif