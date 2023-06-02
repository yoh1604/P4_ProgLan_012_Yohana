/*
 * World class definition
 *
 * You can add another function definitions as you need.
 * You need to implement the populate() and runSimulation() functions.
 * The parameter inside the populate() function is the number of entities
 * You may change the constructor and destructor if you want to.
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include "world.h"
#include "human.h"
#include "zombie.h"
#include "runner.h"
#include "stalker.h"
#include "clicker.h"
#include "bloater.h"

using namespace std;

World::World(int w, int h) : width(w), height(h) {}
World::~World() {}

void World::populate(int human, int runner, int stalker, int clicker, int bloater)
{
  vector<coordinate> pos;
  for(int k = 0; k < 124; k++){
    coordinate temp = {rand() % width, rand() % height};
    bool duplicate = false;
    for (int j = 0; j < k; ++j) {
      if (pos[k].x == temp.x && pos[k].y == temp.y) {
        duplicate = true;
        break;
      }
    }
    if (duplicate) {
      k--;
    } else {
      pos.push_back(temp);
    }
  }
  int indPos = 0;
  for(int i = 0; i < human; i++){
    Human* h = new Human(pos[indPos++]);
    humans.push_back(h);
  }
  for(int i = 0; i < runner; i++){
    Runner* r = new Runner(pos[indPos++]);
    zombies.push_back(r);
  }
  for(int i = 0; i < stalker; i++){
    Stalker* s = new Stalker(pos[indPos++]);
    zombies.push_back(s);
  }
  for(int i = 0; i < clicker; i++){
    Clicker* c = new Clicker(pos[indPos++]);
    zombies.push_back(c);
  }
  for(int i = 0; i < bloater; i++){
    Bloater* b = new Bloater(pos[indPos++]);
    zombies.push_back(b);
  }
}

void World::runSimulation()
{
  // YOUR CODE HERE
  int day = 1;
  int infected = 0;
  int countDown = 7;
  while(true){

    bool isMeet = false;

    cout << "Day " << day << ":" << endl;
    cout << zombies.size() << " Zombies" << endl;
    cout << infected << " Infected Humans" << endl;
    cout << humans.size() << " Humans" << endl;
    infected = 0;
    for(int i = 0; i < humans.size(); i++){
      if(humans[i]->getIsInfected()){
        Runner* r = new Runner(humans[i]->getPos());
        r->setSpawnDay(day);
        zombies.push_back(r);
        humans.erase(humans.begin() + i);
      }
    }

    for(int i = 0; i < zombies.size(); i++){
      if( zombies[i]->getSpawnDay() + zombies[i]->getTransformDay() == day){
        if(zombies[i]->getTransformDay() == 2){
          Stalker* s = new Stalker(zombies[i]->getPos());
          s->setSpawnDay(day);
          zombies.push_back(s);
          zombies.erase(zombies.begin() + i);
        } else if(zombies[i]->getTransformDay() == 4){
          Clicker* c = new Clicker(zombies[i]->getPos());
          c->setSpawnDay(day);
          zombies.push_back(c);
          zombies.erase(zombies.begin() + i);
        } else if(zombies[i]->getTransformDay() == 6){
          Bloater* b = new Bloater(zombies[i]->getPos());
          b->setSpawnDay(day);
          zombies.push_back(b);
          zombies.erase(zombies.begin() + i);
        }
      }
    }
    
    int cycle = 0;
    for(int i = 0; i < zombies.size(); i++){
      for(int j = 0; j < humans.size(); j++){

        int distance = sqrt(pow(zombies[i]->getPos().x - humans[j]->getPos().x, 2) + pow(zombies[i]->getPos().y - humans[j]->getPos().y, 2));
       
        if(distance <= zombies[i]->getRadius()){
  
          isMeet = true;
          cycle++;
          int humanEffAtt = max(humans[j]->getAttack() - zombies[i]->getDefense(), 0);
          int zombieEffAtt = max(zombies[i]->getAttack() - humans[j]->getDefense(), 0);
        
          if(humanEffAtt > zombieEffAtt){
            humans[j]->setPos(zombies[i]->getPos());
            zombies.erase(zombies.begin() + i);
          } else {
            int chance = rand() % 10 + 1;
            if(chance <= zombies[i]->getLethality()*10){
              zombies[i]->setPos(humans[j]->getPos());
              humans.erase(humans.begin() + j);
            } else {
              humans[j]->setIsInfected(true);
              infected++;
            }
          }
            
        }
        if(cycle == 24){
        break;
      }
      }
      if(cycle == 24){
        break;
      }
    }
    day++;
    if(humans.size() == 0){
      cout << "Zombies win!" << endl;
      break;
    } else if(zombies.size() == 0){
      cout << "Humans win!" << endl;
      break;
    }
    if(!isMeet){
      if(countDown == 0){
        cout << "Humans are safe for now..." << endl;
        break;
      } else {
        countDown--;  
      }
    }
  }
}

// You can add another function definitions as you need.