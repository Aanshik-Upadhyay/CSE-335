/**
 * @file Item.cpp
 * @author Aanshik Upadhyay
 * @brief The file for the Item class.
 */
#include "pch.h"
#include "Item.h"
#include "Aquarium.h"


/**
 * Constructor
 * @param aquarium The aquarium this item is a member of
 */
Item::Item(Aquarium *aquarium) : mAquarium(aquarium)
{

}

/**
 * Destructor
 */
Item::~Item()
{

}