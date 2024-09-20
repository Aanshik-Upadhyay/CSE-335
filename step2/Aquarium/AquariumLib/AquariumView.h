/**
 * @file AquariumView.h
 * @author Aanshik Upadhyay
 *
 * @brief View class for our aquarium
 */
 
#ifndef AQUARIUMVIEW_H
#define AQUARIUMVIEW_H
#include "aquarium.h"


/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow
{
private:
    //// Any class wishing to process wxWidgets events must use this macro
    void OnPaint(wxPaintEvent& event);

    /// An object that describes our aquarium
    Aquarium  mAquarium;

public:
    /// Constructor
    void Initialize(wxFrame *parent);
};






#endif ///AQUARIUMVIEW_H
