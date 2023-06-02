/*
 * Bloater class definition
 *
 * You can add function definitions as you need.
 */
#include <iostream>
#include <cstdlib>
#include "bloater.h"

Bloater::Bloater(coordinate pos) : Zombie(pos ,(rand() % 300 +500), (rand() % 400 +600), 15, 0.9, -1) {}