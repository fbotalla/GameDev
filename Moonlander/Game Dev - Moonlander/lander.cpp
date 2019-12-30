#include "lander.h"
#include "uiDraw.h"

#include <cstdlib>

bool Lander::canThrust()
{
   return (isAlive() && !isLanded() && fuel > 0);
}

void Lander::applyGravity(float amount)
{
   velocity.setDy(velocity.getDy() - amount);
}


void Lander:: applyThrustLeft()
{
   if (fuel > 0)
   {
      velocity.setDx(velocity.getDx() + 0.1);
      setFuel(fuel - 1);
   }
}

void Lander:: applyThrustRight()
{
   if (fuel > 0)
   {
      velocity.setDx(velocity.getDx() - 0.1);
      setFuel(fuel - 1);
   }
 
}

void Lander:: applyThrustBottom()
{
   if (fuel >= 3)
   {
      velocity.setDy(velocity.getDy() + 0.3);
      setFuel(fuel - 3);
   }
}


void Lander:: advance()
{
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());
  
}

void Lander::draw() const
{
   
   if (isAlive())
     drawLander(point);
}

bool Lander::lowFuel() 
{
   bool isLow = false;

   if (fuel < 100)
      isLow = true;
   
   return isLow;
}

