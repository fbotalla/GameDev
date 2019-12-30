#ifndef BASEFLYING_H
#define BASEFLYING_H
#include "velocity.h"
#include "point.h"

class BaseFlying
{
protected:
   Velocity velocity;
   Point point;
   bool alive;
public:
   BaseFlying() {}
   Point getPoint() const { return point; }
   Velocity getVelocity() const { return velocity; }
   void setPoint(Point point);
   void setVelocity(Velocity velocity);
   bool isAlive() { return alive; }
   void kill() { alive = false; };
   void advance();
   virtual void draw() = 0;

   ~BaseFlying();
};

#endif