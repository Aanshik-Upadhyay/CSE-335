/**
 * @file Farm.cpp
 * @author Aanshik Upadhyay
 */
 
#include "Farm.h"
#include "Animal.h"
#include <iostream>
using namespace std;
/** Add an animal to the farm inventory.
 *
 * @param animal An animal to add to the inventory
 */
void Farm::AddAnimal(Animal *animal)
{
 mInventory.push_back(animal);
}

/**
 * Farm destructor
 */
Farm::~Farm()
{
 // Iterate over all the animals, destroying
 // each one.
 for (const auto animal : mInventory)
 {
  delete animal;
 }

 // And clear the list
 mInventory.clear();
}
