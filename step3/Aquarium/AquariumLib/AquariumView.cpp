/**
 * @file AquariumView.cpp
 * @author Aanshik Upadhyay
 * @brief The AquariumView class is the class that represents the aquarium view.
 */

#include "pch.h"
#include "AquariumView.h"
#include <wx/dcbuffer.h>
#include "FishMagnemo.h"
#include "FishBeta.h"
#include "FishBubbles.h"
#include "FishAngel.h"

#include "ids.h"
/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
using namespace std;

BEGIN_EVENT_TABLE(AquariumView, wxWindow)
    EVT_PAINT(AquariumView::OnPaint)
    EVT_LEFT_DOWN(AquariumView::OnLeftMouseDown)
    EVT_LEFT_DCLICK(AquariumView::OnLeftMouseDoubleClick)
END_EVENT_TABLE()

/**
 * AquariumView Constructor
 */
AquariumView::AquariumView()
= default;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
 Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
 Create(parent, wxID_ANY);
 SetBackgroundStyle(wxBG_STYLE_PAINT);
  parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
  parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBubblesFish, this, IDM_ADDFISHBUBBLES);
  parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishAngelFish, this, IDM_ADDFISHANGEL);
  parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishMagnemoFish, this, IDM_ADDFISHMAGNEMO);
  Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
  Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
  Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
}
/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void AquariumView::OnPaint(wxPaintEvent& event)
{
 wxAutoBufferedPaintDC dc(this);

 const wxBrush background(*wxWHITE);
 dc.SetBackground(background);
 dc.Clear();

 mAquarium.OnDraw(&dc);
}


/**
 * Menu handler for Add Fish>Beta Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
 const auto fish = make_shared<FishBeta>(&mAquarium);
 mAquarium.Add(fish);
 Refresh();
}

/**
 * Menu handler for Add Fish>Bubbles Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBubblesFish(wxCommandEvent& event)
{
 const auto fish = make_shared<FishBubbles>(&mAquarium);
 mAquarium.Add(fish);
 Refresh();
}
/**
 * Menu handler for Add Fish>Angel Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishAngelFish(wxCommandEvent& event)
{
 auto fish = make_shared<FishAngel>(&mAquarium);
 mAquarium.Add(fish);
 Refresh();
}
/**
 * Menu handler for Add Fish>Magnemo Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishMagnemoFish(wxCommandEvent& event)
{
 const auto fish = make_shared<FishMagnemo>(&mAquarium);
 mAquarium.Add(fish);
 Refresh();
}
/**
 * Handle the left mouse button down event
 * @param event
 */
void AquariumView::OnLeftDown(const wxMouseEvent& event)
{
 const auto item = mAquarium.HitTest(event.GetX(), event.GetY());
 if (item != nullptr) {
  const auto magnemo = dynamic_cast<FishMagnemo*>(item.get());
  if (magnemo != nullptr && magnemo->IsActive()) {
   magnemo->Deactivate();
   Refresh();
  } else {
   mGrabbedItem = item;
   if (mGrabbedItem != nullptr) {
    mAquarium.MoveToEnd(mGrabbedItem);
   }
  }
 }
}

/**
* Handle the left mouse button down event
* @param event
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{

}

/**
 *
 * @param event
 */
void AquariumView::OnLeftMouseDown(wxMouseEvent& event)
{

  }

/**
 *  Handle the left mouse double click event
 * @param event
 */
void AquariumView::OnLeftMouseDoubleClick(wxMouseEvent& event)
{
 const int x = event.GetX();
 const int y = event.GetY();

 /// See if an item is under the mouse
 const auto clickedItem = mAquarium.HitTest(x, y);
 if (clickedItem != nullptr)
 {
  clickedItem->HandleDoubleClick(mAquarium);
  Refresh(); /// Force screen to redraw
 }
}

/**
* Handle the mouse move event
* @param event
*/

void AquariumView::OnMouseMove(wxMouseEvent &event)
{
 /// See if an item is currently being moved by the mouse
 if (mGrabbedItem != nullptr)
 {
  /// If an item is being moved, we only continue to
  /// move it while the left button is down.
  if (event.LeftIsDown())
  {
   mGrabbedItem->SetLocation(event.GetX(), event.GetY());
  }
  else
  {
   /// When the left button is released, we release the item.
   mGrabbedItem = nullptr;
  }

  /// Force the screen to redraw
  Refresh();
 }
}