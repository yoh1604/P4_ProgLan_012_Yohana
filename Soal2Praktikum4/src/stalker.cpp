/*
 * Stalker class definition
 *
 * You can add function definitions as you need.
 */
#include <iostream>
#include <cstdlib>
#include "stalker.h"

Stalker::Stalker(coordinate pos) : Zombie(pos,(rand() % 100 + 200), (rand() % 100 + 200), 12, 0.2, 4) {}