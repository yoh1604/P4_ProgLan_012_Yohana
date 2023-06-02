/*
 * Human class definition
 *
 * You can add function definitions as you need.
 */
#include <iostream>
#include <cstdlib>
#include "human.h"

Human::Human(coordinate pos) : Entity(pos, (rand() % 400 + 200), (rand() % 200 + 200)) {}
Human::~Human() {}
bool Human::getIsInfected() {
    return this->isInfected;
}
void Human::setIsInfected(bool isInfected) {
    this->isInfected = isInfected;
}