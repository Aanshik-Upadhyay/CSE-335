/**
 * @file Animal.h
 * @author Aanshik Upadhyay
 *
 *
 */
 
#ifndef ANIMAL_H
#define ANIMAL_H



class Animal
{
public:
 virtual ~Animal(); /// Destructor
 virtual bool HasDFA() const /// Check if the animal has a dangling fleshy appendage
 {
  return false;
 }

 /** Display an animal. */
 virtual void DisplayAnimal() {}

};



#endif //ANIMAL_H
