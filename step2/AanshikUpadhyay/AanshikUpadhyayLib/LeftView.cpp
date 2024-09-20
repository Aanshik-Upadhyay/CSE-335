/**
 * @file LeftView.cpp
 * @author Aanshik Upadhyay
 *
 * @brief a view class for the left view
 */
#include "pch.h"
#include "LeftView.h"

/**
 * @brief Initialize the left view class.
 *
 * @param parent The parent window for this class.
 */
LeftView::LeftView(wxWindow* parent) : wxPanel(parent)
{
/// Call the base class constructor with parent
    wxWindowBase::SetBackgroundColour(wxColour(24, 69, 59)); /// Go Green!
    /// Create a sizer for the left view
}
