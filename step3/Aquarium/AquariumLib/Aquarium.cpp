/**
 * @file Aquarium.cpp
 * @author Aanshik Upadhyay
 * @brief The Aquarium class is the class that represents the aquarium.
 */
#include "pch.h"
#include "Aquarium.h"
#include "FishBubbles.h"
#include "FishAngel.h"
#include "FishBeta.h"
#include "FishMagnemo.h"

using namespace std;

/// The distance to pull fish towards the active Magnemo
constexpr double PullDistance = 100;

/**
 * Aquarium Constructor
 */
Aquarium::Aquarium()
{
 mBackground = make_unique<wxBitmap>(
         L"images/background1.png", wxBITMAP_TYPE_ANY);
}

/**
* Draw the aquarium
* @param dc The device context to draw on
*/
void Aquarium::OnDraw(wxDC *dc)
{
 dc->DrawBitmap(*mBackground, 0, 0);
 wxFont font(wxSize(0, 20),
         wxFONTFAMILY_SWISS,
         wxFONTSTYLE_NORMAL,
         wxFONTWEIGHT_NORMAL);
 dc->SetFont(font);
 dc->SetTextForeground(wxColour(0, 64, 0));
 dc->DrawText(L"Under the Sea!", 10, 10);
 for (auto item : mItems)
 {
  item->Draw(dc);
 }
}

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/**
 * Add an item to the aquarium
 * @param item New item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
 item->SetLocation(InitialX, InitialY);
 mItems.push_back(item);
}
/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
 for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
 {
  if ((*i)->HitTest(x, y))
  {
   return *i;
  }
 }

 return  nullptr;
}

/**
 * Move an item to the end of the list of items
 * @param item Item to move
 */
void Aquarium::MoveToEnd(const std::shared_ptr<Item>& item)
{
 if (const auto loc = find(mItems.begin(), mItems.end(), item); loc != mItems.end()) {
  mItems.erase(loc);
  mItems.push_back(item);
 }
}


/**
 * Move the fish towards the active Magnemo
 * @param activeMagnemo The active Magnemo
 */
void Aquarium::MoveFishTowardsMagnemo(const FishMagnemo* activeMagnemo) const
{
 // Get the coordinates of the active Magnemo
 double xg = activeMagnemo->GetX();
 double yg = activeMagnemo->GetY();

 // Iterate over all items (fish) in the aquarium
 for (const auto& item : mItems)
 {
  // Skip the active Magnemo itself
  if (item.get() == activeMagnemo) continue;

  // Get coordinates of the other fish
  const double xo = item->GetX();
  const double yo = item->GetY();

  // Calculate the vector from the active Magnemo to the other fish
  const double deltaX = xo - xg;
  const double deltaY = yo - yg;

  // Calculate the distance between the active Magnemo and the other fish
  const double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

  // Prevent division by zero (i.e., the fish is at the exact same location)
  if (distance == 0) continue;

  // Calculate the movement vector based on the PullDistance
  const double moveX = deltaX * (PullDistance / distance);
  const double moveY = deltaY * (PullDistance / distance);

  // Move the fish; if the distance is less than 100 pixels, move them directly to the target
  if (distance < PullDistance)
  {
   item->SetLocation(xo - deltaX, yo - deltaY);  // Move directly to Magnemo
  }
  else
  {
   item->SetLocation(xo - moveX, yo - moveY);  // Move by the PullDistance
  }
 }
}

