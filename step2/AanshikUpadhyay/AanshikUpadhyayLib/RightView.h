/**
 * @file RightView.h
 * @author Aanshik Upadhyay
 *
 * @brief a view class for the right side of the main window
 */
 
#ifndef RIGHTVIEW_H
#define RIGHTVIEW_H


/// a view class for the right side of the main window
class RightView : public wxPanel {
private:
 void OnPaint(wxPaintEvent& event);
public:
 explicit RightView(wxWindow* parent);


};




#endif ///RIGHTVIEW_H
