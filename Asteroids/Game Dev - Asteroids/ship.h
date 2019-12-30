#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#define M_PI 3.14159265358979323846

#include "flyingObject.h"

// Put your Ship class here
class Ship : public FlyingObject
{
private:
   float angle = 0.0;
   
 public:
    Ship(const Point &point)  { setSize(SHIP_SIZE); angle = 270.0; }

   float getAngle() const { return angle; }
   Point getPoint() const { return point; }
  
   void draw();
   void drawInvincible();
   void moveShip(const Interface & ui);
};

#endif /* ship_h */
