/**
 * @file Farm.h
 * @author Aanshik Upadhyay *
 *
 *Class that describes a farm.
 *
 *This class holds a collection of animals that make up the inventory of a farm.
 */

#ifndef FARM_H
#define FARM_H
#include <vector>
#include <iostream>
#include "Animal.h"

/**
 * Class that describes a farm.
 *
 * Holds a collection of animals that make up the farm
 * inventory.
 */
class Farm
{
private:
 /// A list with the inventory of all animals on the farm
 std::vector<Animal *> mInventory;


public:
 ~Farm();
 /// Add an animal to the farm inventory
 void AddAnimal(Animal* animal);
/// Display the inventory of the farm
 void DisplayInventory() const
 {
  for (const auto animal : mInventory)
  {
   animal->DisplayAnimal();
  }
 }
 void DisplayDFA(int index = 0, int count = 0) const /// Display the number of animals with a dangling fleshy appendage
 {
  if (index == mInventory.size()) /// once we have checked all the animals
   {

   std::cout << "There are " << count << " animals with a dangling fleshy appendage." << std::endl;
   return;
  }

  /// Check if the current animal has a DFA
  if (mInventory[index]->HasDFA())
   {
   DisplayDFA(index + 1, count + 1);
   }
  else
   {
   DisplayDFA(index + 1, count);
   }
 }

};


#endif //FARM_H
