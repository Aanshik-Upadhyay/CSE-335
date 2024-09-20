/**
 * @file AquariumView.h
 * @author Aanshik Upadhyay
 *
 * @brief aquarium view class
 */

#ifndef AQUARIUMVIEW_H
#define AQUARIUMVIEW_H

#include <wx/wx.h>
/// a view class for the aquarium
class AquariumView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);

public:
    AquariumView(wxWindow *parent); // Add constructor that accepts wxWindow*
    void Initialize(wxFrame *parent);
};



#endif ///AQUARIUMVIEW_H
