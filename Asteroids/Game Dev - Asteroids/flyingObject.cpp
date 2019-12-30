#include "flyingObject.h"



// Put your FlyingObject method bodies here
void FlyingObject::setPoint(Point point)
{
   this->point = point;
}

void FlyingObject::setVelocity(Velocity velocity)
{
   this->velocity = velocity;
}

void FlyingObject::advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy()); 
}

void FlyingObject::wrap(Point tl, Point br)
{
   int newX = point.getX() + velocity.getDx();
   int newY = point.getY() + velocity.getDy();

   if (newX > 200)
   {
      newX -= 400;
   }
   if (newX < -200)
   {
      newX += 400;
   }
   if (newY > 200)
   {
      newY -= 400;
   }
   if (newY < -200)
   {
      newY += 400;
   }
   point.setY(newY);
   point.setX(newX);
}