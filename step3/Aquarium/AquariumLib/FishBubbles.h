/**
 * @file FishBubbles.h
 * @author Aanshik Upadhyay
 * @brief The file for the FishBubbles class.
 *
 *
 */
 
#ifndef AQUARIUM_FISHBUBBLES_H
#define AQUARIUM_FISHBUBBLES_H

#include "Item.h"

/**
 * Class for a fish bubbles in our aquarium
 */
class FishBubbles final : public Item
{
private:
 /// The underlying fish image
 std::unique_ptr<wxImage> mFishImage;

 /// The bitmap we can display for this fish
 std::unique_ptr<wxBitmap> mFishBitmap;

public:
 /// Default constructor (disabled)
 FishBubbles() = delete;

 /// Copy constructor (disabled)
 FishBubbles(const FishBubbles &) = delete;

 /// Assignment operator
 void operator=(const FishBubbles &) = delete;

 explicit FishBubbles(Aquarium* aquarium);
 void Draw(wxDC *dc) override;
 bool HitTest(int x, int y) override;
};



#endif ///FISHBUBBLES_H
