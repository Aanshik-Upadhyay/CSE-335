/**
* @file Cow.h
 *
 * @author Aanshik Upadhyay
 *
 * Class that describes a cow
 */

#ifndef STEP1_COW_H
#define STEP1_COW_H
#include "Animal.h"
#include <string>

/**
 * Class that describes a cow
 */
class Cow : public Animal
{
private:
    /// The types of cow we can have on our farm
    enum class Type {Bull, BeefCow, MilkCow};



    /// The cow's name
    std::string mName;

    /// The type of cow: Bull, BeefCow, or MilkCow
    Type mType =Type::MilkCow;

    /// The milk production for a cow in gallons per day
    double mMilkProduction = 0;

    /// Gender of the cow for DFA.

public:

    void ObtainCowInformation(); /// Obtain information from the user about this cow.
    void DisplayAnimal(); /// Display the cow.
    bool HasDFA() const; /// Check if the cow has a dangling fleshy appendage.
    ~Cow();
};


#endif //STEP1_COW_H