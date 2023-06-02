/*
 * Zombie class definition
 *
 * You can add function definitions as you need.
 */
#include <iostream>
#include "zombie.h"

Zombie::Zombie(coordinate pos, int attack, int defense, int radius, int lethality, int transformDay) 
: 
Entity(pos, attack, defense), radius(radius), lethality(lethality), spawnDay(1), transformDay(transformDay) {}

Zombie::~Zombie() {}    
int Zombie::getRadius() {
    return radius;
}
int Zombie::getLethality() {
    return lethality;
}
int Zombie::getSpawnDay() {
    return spawnDay;
}
void Zombie::setSpawnDay(int spawnDay) {
    this->spawnDay = spawnDay;
}
int Zombie::getTransformDay() {
    return transformDay;
}