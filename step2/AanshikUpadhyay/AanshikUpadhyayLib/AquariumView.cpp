/**
 * @file AquariumView.cpp
 * @author Aanshik Upadhyay
 * @brief aquarium view class
 */

#include "pch.h"
#include "AquariumView.h"
#include <wx/dcbuffer.h>
/**
 * @brief Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
AquariumView::AquariumView(wxWindow *parent)
    : wxWindow(parent, wxID_ANY) // Initialize the base class with the parent
{
 Initialize(dynamic_cast<wxFrame*>(parent));
}

void AquariumView::Initialize(wxFrame* parent)
{
 Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
 SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void AquariumView::OnPaint(wxPaintEvent& event)
{
 wxAutoBufferedPaintDC dc(this);

 wxBrush background(*wxWHITE);
 dc.SetBackground(background);
 dc.Clear();

 dc.DrawLine(100, 100, 300, 200);
}

