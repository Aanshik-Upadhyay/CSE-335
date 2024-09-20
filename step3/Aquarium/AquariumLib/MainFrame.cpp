/**
 * @file MainFrame.cpp
 * @author Aanshik Upadhyay
 * @brief The top-level (main) frame of the application
 */
#include "pch.h"
#include "MainFrame.h"
#include "AquariumView.h"
#include "ids.h"
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
 const auto menuBar = new wxMenuBar( );

 const auto fileMenu = new wxMenu();
 const auto helpMenu = new wxMenu();
 const auto fishMenu = new wxMenu();

 menuBar->Append(fileMenu, L"&File" );
 menuBar->Append(fishMenu, L"&Add Fish");
 menuBar->Append(helpMenu, L"&Help");

 fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
 helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
 fishMenu->Append(IDM_ADDFISHBETA, L"&Beta Fish", L"Add a Beta Fish");
 fishMenu->Append(IDM_ADDFISHBUBBLES, L"&Bubbles Fish", L"Add a Bubbles Fish");
 fishMenu->Append(IDM_ADDFISHANGEL, L"&Angel Fish", L"Add an Angel Fish");
 fishMenu->Append(IDM_ADDFISHMAGNEMO, L"&Magnemo Fish", L"Add an Magnemo Fish");
 SetMenuBar( menuBar );
 CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
 Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
 Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
 Close(true);
}


/**
 * About menu option handlers
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
 wxMessageBox(L"Welcome to the Aquarium!", L"About Aquarium", wxOK, this);
}