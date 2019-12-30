#ifndef flyingObject_h
#define flyingObject_h

#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"

#include <cmath>


class FlyingObject : public Point
{
protected:

   Velocity velocity;
   Point point;
   bool alive;
   float rotate;
   int size;

public:
   FlyingObject() {  alive = true; }
   ~FlyingObject() { alive = false; }

   void advance();

   virtual void draw() {};

   Velocity getVelocity() const { return velocity; }
   void setVelocity(Velocity velocity);

   Point getPoint() const { return point; }
   void setPoint(Point point);

  
   void wrap(Point tl, Point br);

   bool isAlive() { return alive; }
   void kill() { alive = false; };

   float getSize() const { return size; }
   void setSize(float size) { this->size = size; }
};

#endif


