/**
 * @file MainFrame.cpp
 * @author Aanshik Upadhyay
 */
#include "pch.h"
#include "MainFrame.h"
#include "AquariumView.h"
/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
 /// Create the main frame
 Create(nullptr, wxID_ANY, L"Aquarium", wxDefaultPosition,  wxSize( 1000,800 ));

 /// Create a sizer
 auto sizer = new wxBoxSizer( wxVERTICAL );

 /// Create the aquarium view
 auto aquariumView = new AquariumView();
 aquariumView->Initialize(this);

 /// Add the aquarium view to the sizer
 sizer->Add(aquariumView,1, wxEXPAND | wxALL );

 /// Set the sizer
 SetSizer( sizer );

 // Layout the sizer
 Layout();
}