/**
 * @file RightView.cpp
 * @author Aanshik Upadhyay
 * @brief a view class for the right side of the main window
 */
#include "pch.h"
#include "RightView.h"
#include <wx/dcbuffer.h>



/**
 * @brief Initialize the left view class.
 *
 * @param parent The parent window for this class.
 */

RightView::RightView(wxWindow* parent)
    : wxPanel(parent) // Initialize the base class with the parent
{
    Bind(wxEVT_PAINT, &RightView::OnPaint, this);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void RightView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Draw a line as an example
    dc.DrawLine(100, 100, 300, 200);
}