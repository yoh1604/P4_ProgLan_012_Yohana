/*
 * Clicker class definition
 *
 * You can add function definitions as you need.
 */
#include <iostream>
#include <cstdlib>
#include "clicker.h"

Clicker::Clicker(coordinate pos) : Zombie(pos ,(rand() % 200 + 400), (rand() % 200 + 300), 11, 0.8, 6) {}