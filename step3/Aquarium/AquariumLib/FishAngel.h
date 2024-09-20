/**
 * @file FishAngel.h
 * @author Aanshik Upadhyay
 * @brief FishAngel class for our aquarium
 *
 *
 */
 
#ifndef FISHANGEL_H
#define FISHANGEL_H


#include "Item.h"

/**
 * Class representing a fish angel in our aquarium
 */
class FishAngel final : public Item
{
private:
 /// The underlying fish image
 std::unique_ptr<wxImage> mFishImage;

 /// The bitmap we can display for this fish
 std::unique_ptr<wxBitmap> mFishBitmap;

public:
 /// Default constructor (disabled)
 FishAngel() = delete;

 /// Copy constructor (disabled)
 FishAngel(const FishAngel &) = delete;

 /// Assignment operator
 void operator=(const FishAngel &) = delete;

 explicit FishAngel(Aquarium* aquarium);
 void Draw(wxDC *dc) override;
 bool HitTest(int x, int y) override;
};




#endif ///FISHANGEL_H
