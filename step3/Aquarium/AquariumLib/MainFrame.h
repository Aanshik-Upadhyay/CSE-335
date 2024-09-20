/**
 * @file MainFrame.h
 * @author Aanshik Upadhyay
 *
 * @brief The top-level (main) frame of the application
 */

#ifndef MAINFRAME_H
#define MAINFRAME_H

/**
 * The top-level (main) frame of the application
 */
class MainFrame: public wxFrame
{
private:

public:
 void Initialize();
 void OnExit(wxCommandEvent& event);
 void OnAbout(wxCommandEvent& event);
};



#endif /// MAINFRAME_H

