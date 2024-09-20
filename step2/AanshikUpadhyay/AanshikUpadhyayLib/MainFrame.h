/**
 * @file MainFrame.h
 * @author Aanshik Upadhyay
 *
 * @brief The top-level (main) frame of the application
 */

#ifndef MAINFRAME_H
#define MAINFRAME_H

/// Include the necessary headers
class LeftView;
class RightView;

/// The main frame of the application
class MainFrame : public wxFrame {
private:
    LeftView* leftView{};
    RightView* rightView{};

public:
    MainFrame();
};

#endif //MAINFRAME_H
