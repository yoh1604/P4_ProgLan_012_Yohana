/*
 * Bloater class
 *
 * You can add any member variables or functions you need to this class.
 * This class derives from the Zombie class.
 * Bloater Stats:
 * - Attack: 500-800
 * - Defense: 600-1000
 * - Lethality: 0.9
 * - Radius: 15
 */
#ifndef BLOATER_H
#define BLOATER_H

#include "zombie.h"

class Bloater : public Zombie
{
    public :
        Bloater(coordinate);
};

#endif