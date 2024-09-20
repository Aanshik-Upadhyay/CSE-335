/**
 * @file FishBeta.cpp
 * @author Aanshik Upadhyay
 * @brief FishBeta class for our aquarium
 */
 
#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"
#include <string>
#include "Item.h"
using namespace std;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Item(aquarium)
{
 mFishImage = make_unique<wxImage>(FishBetaImageName, wxBITMAP_TYPE_ANY);
 mFishBitmap = make_unique<wxBitmap>(*mFishImage);
}

/**
 * Draw this fish
 * @param dc Device context to draw on
 */

void FishBeta::Draw(wxDC *dc)
{
 const double wid = mFishBitmap->GetWidth();
 const double hit = mFishBitmap->GetHeight();
 dc->DrawBitmap(*mFishBitmap,
         static_cast<int>(GetX() - wid / 2),
         static_cast<int>(GetY() - hit / 2));
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool FishBeta::HitTest(int x, int y)
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