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
 *
 */
class AquariumView final : public wxWindow
{
private:
    //// Any class wishing to process wxWidgets events must use this macro
    auto OnPaint(wxPaintEvent& event) -> void;
    void OnAddFishBetaFish(wxCommandEvent& event);
    void OnAddFishBubblesFish(wxCommandEvent& event);
    void OnAddFishAngelFish(wxCommandEvent& event);
    void OnAddFishMagnemoFish(wxCommandEvent& event);
    void OnLeftDown(const wxMouseEvent& event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnLeftMouseDown(wxMouseEvent& event);
    void OnLeftMouseDoubleClick(wxMouseEvent& event);

    /// Any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();
    /// The item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;
    /// An object that describes our aquarium
    Aquarium  mAquarium;

public:
    /**
     * Constructor
     * @param parent The parent window for this view
     */
    AquariumView(wxFrame* parent);
    /// Default constructor
    AquariumView();

    /// Constructor
    void Initialize(wxFrame *parent);

};






#endif ///AQUARIUMVIEW_H
