/**
 * @file Item.h
 * @author Aanshik Upadhyay
 *
 * @brief Base class for any item in our aquarium.
 *
 */
 
#ifndef ITEM_H
#define ITEM_H


class Aquarium;


/**
 * Base class for any item in our aquarium.
 */
class Item
{
private:
 /// The aquarium this item is contained in
 Aquarium   *mAquarium;

 /// Item location in the aquarium
 double  mX = 0;     ///< X location for the center of the item
 double  mY = 0;     ///< Y location for the center of the item

protected:
 explicit Item(Aquarium *aquarium);

public:
 /// Default constructor (disabled)
 Item() = delete;

 /// Copy constructor (disabled)
 Item(const Item &) = delete;

 /// Assignment operator
 void operator=(const Item &) = delete;
 /**
    * The X location of the item
    * @return X location in pixels
    */
 double GetX() const
 {
  return mX;
 }

 /**
  * The Y location of the item
  * @return Y location in pixels
  */
 double GetY() const
 {
  return mY;
 }

 /**
  * Set the item location
  * @param x X location in pixels
  * @param y Y location in pixels
  */
 void SetLocation(double x, double y) { mX = x; mY = y; }
 virtual ~Item();
};



#endif //ITEM_H
