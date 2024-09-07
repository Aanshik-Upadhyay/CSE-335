/**
 * @file Turkey.h
 * @author Aanshik Upadhyay
 *
 *
 */

#ifndef TURKEY_H
#define TURKEY_H



#include <string>
#include "Animal.h"
/** Class that describes a Turkey.
*/
class Turkey : public Animal
{
private:
 /// The Turkey's Name
 std::string mName;
 /// types of Turkey we have on the farm
 enum class Type {Hen, Tom};
 enum class dType {Snooded, Desnooded};
 /// The type of Turkey: Hen or Tom
 Type mType = Type::Hen;
 dType mdType = dType::Snooded;



public:

 void ObtainTurkeyInformation(); /// Obtain a Turkey description from the user.
 void DisplayAnimal(); /// Display the Turkey.
 bool HasDFA() const; /// Check if the Turkey has a dangling fleshy appendage.
 ~Turkey();


};



#endif //TURKEY_H
