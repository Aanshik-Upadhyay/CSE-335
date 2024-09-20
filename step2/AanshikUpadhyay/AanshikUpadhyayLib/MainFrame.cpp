/**
 * @file MainFrame.cpp
 * @author Aanshik Upadhyay
 * @brief A class for the main frame of the application.
 */
#include "pch.h"
#include "MainFrame.h"
#include "LeftView.h"
#include "RightView.h"


MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "Aanshik Upadhyay", wxDefaultPosition, wxSize(1000, 800)) {
    auto* sizer = new wxBoxSizer(wxHORIZONTAL);

    auto* leftView = new LeftView(this);
    auto* rightView = new RightView(this); // This will handle drawing

    sizer->Add(leftView, 1, wxEXPAND);
    sizer->Add(rightView, 3, wxEXPAND); // Adjust proportion as needed

    SetSizer(sizer);
    Layout();
}
