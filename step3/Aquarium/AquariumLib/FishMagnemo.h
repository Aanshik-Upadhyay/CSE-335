/**
 * @file FishMagnemo.h
 * @author Aanshik Upadhyay
 * @brief Class for a magnemo fish in our aquarium
 *
 *
 */
 
#ifndef FISHMAGNEMO_H
#define FISHMAGNEMO_H



#include "Item.h"
#include "Aquarium.h"

/**
 * Class for a magnemo fish in our aquarium
 */
class FishMagnemo : public Item
{
private:
 /// The underlying fish image
 std::unique_ptr<wxImage> mFishImage;

 /// The bitmap we can display for this fish
 std::unique_ptr<wxBitmap> mFishBitmap;

/// Is the fish active?
 bool mIsActive = false;

public:
 /**
  *  Handle double click on the fish
  * @param aquarium
  */
 void HandleDoubleClick(Aquarium& aquarium) override {
  Activate();
  aquarium.MoveFishTowardsMagnemo(this);
 }
 void Activate();

 static const std::wstring FishDormantMagnemoImageName;
 static const std::wstring FishActiveMagnemoImageName;
 /// Default constructor (disabled)
 FishMagnemo() = delete;

 /// Copy constructor (disabled)
 FishMagnemo(const FishMagnemo &) = delete;

 /// Assignment operator
 void operator=(const FishMagnemo &) = delete;

 explicit FishMagnemo(Aquarium* aquarium);
 void Draw(wxDC *dc) override;
 bool HitTest(int x, int y) override;
 [[nodiscard]] bool IsActive() const; /// Is the fish active?
 void Deactivate();
};



#endif /// FISHMAGNEMO_H
