/*
 * Entity class definition
 *
 * You can add function definitions as you need.
 */

#include <iostream>
#include <cstdlib>
#include "entity.h"

Entity::Entity(coordinate pos, int attack, int defense) : pos(pos), attack(attack), defense(defense) {}

Entity::~Entity() {}

void Entity::setPos(coordinate pos) {
    this->pos = pos;
}

coordinate Entity::getPos() {
    return this->pos;
}

int Entity::getAttack() {
    return this->attack;
}

int Entity::getDefense() {
    return this->defense;
}

int Entity::getRadius() {
    return 0;
}