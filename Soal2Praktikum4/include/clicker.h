/*
 * Clicker class
 *
 * You can add any member variables or functions you need to this class.
 * This class derives from the Zombie class.
 * Clicker Stats:
 * - Attack: 400-600
 * - Defense: 300-500
 * - Lethality: 0.8
 * - Radius: 11
 */
#ifndef CLICKER_H
#define CLICKER_H

#include "zombie.h"

class Clicker : public Zombie
{
    public :
        Clicker(coordinate);
};

#endif