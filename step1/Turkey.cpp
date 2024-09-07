/**
 * @file Turkey.cpp
 * @author Aanshik Upadhyay
 */
#include <iostream>
#include "Turkey.h"
using namespace std;

/**
 * Obtain a turkey description from the user.
 */
void Turkey::ObtainTurkeyInformation()
{
    cout << endl;
    cout << "Input information about the Turkey" << endl;

    // Obtain the name. This is easy, since it's just a
    // string.
    cout << "Name: ";
    cin >> mName;

    // Obtain the type of Turkey
    bool valid = false; // Flag to check if the input is valid
    while (!valid)
    {
        cout << "1: Hen" << endl;
        cout << "2: Tom" << endl;
        cout << "Enter selection and return: ";
        int option;
        cin >> option;
        if (!cin)
        {
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (option)
        {
        case 1:
            mType = Type::Hen;
            valid = true;
            break;

        case 2:
            mType = Type::Tom;
            valid = true;
            break;
        }
    }

    valid = false; // Reset the valid flag for the next input
    while (!valid)
    {
        cout << "Desnooded? [y/n]: ";
        char option;
        cin >> option;
        if (!cin)
        {
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }
        switch (option)
        {
        case 'y':
        case 'Y':
            mdType = dType::Desnooded;
            valid = true;
            break;

        case 'n':
        case 'N':
            mdType = dType::Snooded;
            valid = true;
            break;
        }
    }
}

/**
 * Display the Turkey.
 */
void Turkey::DisplayAnimal()
{
    cout << "Turkey " << mName;
    switch (mType)
    {
    case Type::Hen:
        cout << " is a Hen";
        break;

    case Type::Tom:
        cout << " is a Tom";
        break;
    }

    cout << " and it is ";
    switch (mdType)
    {
    case dType::Snooded:
        cout << "snooded" << endl;
        break;

    case dType::Desnooded:
        cout << "desnooded" << endl;
        break;
    }
}
bool Turkey::HasDFA() const /// Check if the Turkey has a dangling fleshy appendage
{
    return mdType == dType::Snooded;
}

Turkey::~Turkey()
{

}