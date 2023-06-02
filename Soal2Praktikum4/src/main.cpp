/*
 * main.cpp
 * DO NOT EDIT THIS FILE
 */

#include <stdlib.h>
#include <time.h>

#include "world.h"

#define WORLD_WIDTH 100 // Based on the problem statement
#define WORLD_HEIGHT 100
#define NUM_HUMANS 100
#define NUM_RUNNERS 10
#define NUM_STALKERS 8
#define NUM_CLICKERS 4
#define NUM_BLOATERS 2

int main()
{
  srand(time(NULL));
  World world(WORLD_WIDTH, WORLD_HEIGHT);
  world.populate(NUM_HUMANS, NUM_RUNNERS, NUM_STALKERS, NUM_CLICKERS, NUM_BLOATERS);
  world.runSimulation();

  return 0;
}