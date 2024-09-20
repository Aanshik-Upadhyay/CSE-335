/**
 * @file Aquarium.h
 * @author Aanshik Upadhyay
 *
 * @brief The Aquarium class is the class that represents the aquarium.
 */
 
#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <memory>

/**
 *  @brief The Aquarium class is the class that represents the aquarium.
 *  @param mBackground Background image to use
 */
class Aquarium
{
private:
 std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

public:
 void OnDraw(wxDC* dc);
 Aquarium();
};



#endif //AQUARIUM_H
