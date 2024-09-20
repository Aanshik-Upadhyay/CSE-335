/**
* @file AanshikUpadhyayApp.cpp
 * @author Aanshik Upadhyay
 * @brief the main application class
 */
#include "pch.h"
#include "AanshikUpadhyayApp.h"
#include <MainFrame.h>

#ifdef WIN32
#define CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#endif

/**
 * @brief Initialize the application.
 * @return
 */
bool AanshikUpadhyayApp::OnInit()
{
#ifdef WIN32
 _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

 if (!wxApp::OnInit())
 {
  return false;
 }
 /// Add image type handlers
 wxInitAllImageHandlers();
 const auto frame = new MainFrame();
 frame->Show(true);

 return true;
}