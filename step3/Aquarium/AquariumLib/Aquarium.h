/**
 * @file Aquarium.h
 * @author Aanshik Upadhyay
 *
 * @brief The Aquarium class is the class that represents the aquarium.
 */
 
#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <memory>
#include "Item.h"
#include <vector>


class FishMagnemo;

/**
 *  @brief The Aquarium class is the class that represents the aquarium.
 *  @param mBackground Background image to use
 */


class Aquarium
{
private:
 /// All the items to populate our aquarium
 std::vector<std::shared_ptr<Item>> mItems;
 std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

public:
 void OnDraw(wxDC* dc);
 void Add(std::shared_ptr<Item> item);
 std::shared_ptr<Item> HitTest(int x, int y);
 void MoveToEnd(const std::shared_ptr<Item>& item); /// Move item to end of list
 void MoveFishTowardsMagnemo(const FishMagnemo* activeMagnemo) const; ///< Move fish towards magnemo
 Aquarium();
};



#endif //AQUARIUM_H
