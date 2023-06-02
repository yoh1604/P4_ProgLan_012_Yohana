/*
 * Runner class
 *
 * You can add any member variables or functions you need to this class.
 * This class derives from the Zombie class.
 * Runner Stats:
 * - Attack: 100-200
 * - Defense: 100-200
 * - Lethality: 0.1
 * - Radius: 13
 */
#ifndef RUNNER_H
#define RUNNER_H

#include "zombie.h"

class Runner : public Zombie
{
    public :
        Runner(coordinate);
};

#endif