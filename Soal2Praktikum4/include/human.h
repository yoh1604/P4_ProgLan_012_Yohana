/*
 * Human class
 *
 * You can add any member variables or functions you need to this class.
 * This class derives from the Entity class.
 * Human Stats:
 * - Attack: 200-600
 * - Defense: 200-400
 */
#ifndef HUMAN_H
#define HUMAN_H

#include "entity.h"

class Human : public Entity
{
    private :
        bool isInfected = false;
    public :
        Human(coordinate);
        ~Human();
        bool getIsInfected();
        void setIsInfected(bool);
};

#endif