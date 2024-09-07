/**
* @file main.cpp
 *
 * @author Aanshik Upadhyay
 * The main file with the menu and the main function calling all other functions.
 *
 */

#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#endif
#include <iostream>
#include "Farm.h"
#include "Cow.h"
#include "Chicken.h"
#include "Animal.h"
#include "Turkey.h"

using namespace std;

/**
 * Main entry point.
 *
 * This is where the program starts.
 * @return 0
 */
int main()
{
#ifdef WIN32
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif
    cout << "Instantiating Farm" << endl;
    Farm farm;

    // This loops continuously until we are done
    bool done = false;
    while (!done)
    {
        // Output user instructions
        cout << endl;
        cout << "Farm management" << endl;
        cout << "1 - Add cow" << endl;
        cout << "2 - Add Chicken" << endl;
        cout << "3 - Add Turkey" << endl;
        cout << "8 - Add Animals with a dangling fleshy appendage" << endl;
        cout << "9 - List inventory" << endl;
        cout << "99 - Exit" << endl;
        cout << "Select Option: ";

        // Get option from the user
        int option;
        cin >> option;

        // Handle invalid  input
        if (!cin)
        {
            option = 1000;
            cin.clear();
            cin.ignore();  // Discard bad input
        }

        // Handle the possible user options
        switch (option)
        {
        case 1:
            {
                cout << "Adding cow" << endl;
                Cow *cow = new Cow();
                cow->ObtainCowInformation();
                farm.AddAnimal(cow);
            }
            break;
        case 2:
            {
                cout << "Adding chicken" << endl;
                Chicken *chicken = new Chicken();
                chicken->ObtainChickenInformation();
                farm.AddAnimal(chicken);
            }
            break;

        case 3:
            {
                cout << "Adding Turkey" << endl;
                 Turkey *turkey = new Turkey();
                turkey->ObtainTurkeyInformation();
                farm.AddAnimal(turkey);
            }

        case 8:
            farm.DisplayDFA();
            break;

        case 9:
            farm.DisplayInventory();
            break;


        case 99:
            done = true;
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    return 0;
}