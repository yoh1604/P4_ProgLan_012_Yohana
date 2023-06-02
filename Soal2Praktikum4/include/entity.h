/*
 * Entity class
 *
 * You can add any member variables or functions you need to this class.
 * This class the base class for humans and all zombies.
 */
#ifndef ENTITY_H
#define ENTITY_H

struct coordinate
{
    int x;
    int y;
};


class Entity
{
    protected :
        coordinate pos;
        int attack;
        int defense;
    public :
        Entity(coordinate, int, int);
        ~Entity();
        void setPos(coordinate);
        coordinate getPos();
        int getAttack();
        int getDefense();
        virtual int getRadius();
};

#endif