/*
 * World class
 *
 * This class represents the world in which the simulation takes place. You can add
 * any member variables or functions you need to this class. The requirement
 * is that you have a constructor that takes in the width and height of the world
 * as parameters, `populate` function that populates the world with entities, and
 * a `runSimulation` function that runs the simulation.
 */
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include "entity.h"
#include "human.h"
#include "zombie.h"

using namespace std;

class World
{
public:
  World(int w, int h);
  ~World();                                                                    // Destructor
  void populate(int human, int runner, int stalker, int clicker, int bloater); // Populate the world with entities
  void runSimulation();                                                        // Run the simulation
private:
  int width;  // Width of the world
  int height; // Height of the world
  // vector<Entity *> entities;
  vector<Human *> humans;
  vector<Zombie *> zombies;
};

#endif