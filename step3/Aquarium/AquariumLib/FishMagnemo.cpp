/**
 * @file FishMagnemo.cpp
 * @author Aanshik Upadhyay
 * @brief The FishMagnemo class is the class that represents the magnemo fish.
 */

#include "pch.h"
#include "FishMagnemo.h"
#include "Aquarium.h"
#include <string>
#include "Item.h"
using namespace std;



/// Fish filename
const wstring FishMagnemo::FishDormantMagnemoImageName = L"images/magnemo.png";
/// Fish filename
const wstring FishMagnemo::FishActiveMagnemoImageName = L"images/magnemo-a.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishMagnemo::FishMagnemo(Aquarium *aquarium) : Item(aquarium)
{

 /// Load the dormant image for the first time
 mFishImage = make_unique<wxImage>(FishDormantMagnemoImageName, wxBITMAP_TYPE_ANY);
 mFishBitmap = make_unique<wxBitmap>(*mFishImage);
}

/**
 * Draw this fish
 * @param dc Device context to draw on
 */
void FishMagnemo::Draw(wxDC *dc)
{

 /// If the fish is active, use the active image instead of the dormant image

 if (mIsActive)
 {
  mFishImage = make_unique<wxImage>(FishActiveMagnemoImageName, wxBITMAP_TYPE_ANY);
 }
 else
 {
  mFishImage = make_unique<wxImage>(FishDormantMagnemoImageName, wxBITMAP_TYPE_ANY);
 }
 mFishBitmap = make_unique<wxBitmap>(*mFishImage);

 const double wid = mFishBitmap->GetWidth();
 const double hit = mFishBitmap->GetHeight();
 dc->DrawBitmap(*mFishBitmap,
                static_cast<int>(GetX() - wid / 2),
                static_cast<int>(GetY() - hit / 2));
}

/**
 * Test to see if we hit this object with a mouse.
 * gives true if hit.
 */
void FishMagnemo::Activate()
{
 mIsActive = true;
}

/**
 *  Deactivate the magnemo fish
 *
 */
void FishMagnemo::Deactivate()
{
 mIsActive = false;
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool FishMagnemo::HitTest(const int x, const int y)
{
 const double wid = mFishBitmap->GetWidth();
 const double hit = mFishBitmap->GetHeight();



 /// Make x and y relative to the top-left corner of the bitmap image
 /// Subtracting the center makes x, y relative to the image center
 /// Adding half the size makes x, y relative to the image top corner

 const double testX = x - GetX() + wid / 2;
 const double testY = y - GetY() + hit / 2;

 /// Test to see if x, y are in the image
 if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
 {
  /// We are outside the image
  return false;
 }

 /// Test to see if x, y are in the drawn part of the image
 /// If the location is transparent, we are not in the drawn
 /// part of the image
 return !mFishImage->IsTransparent(static_cast<int>(testX), static_cast<int>(testY));
}

/**
 * @brief Get the state of the magnemo fish
 * @return true if the fish is active
 */
bool FishMagnemo::IsActive() const
{
 return mIsActive;
}