#include "rocks.h"

// Put your Rock methods here

Rock::Rock()
{
   point.setX(getX());
   point.setY(getY());

   velocity.setDx(random(-1, 1));
   velocity.setDy(random(-1, 1));
   if (velocity.getDx() == 0)
   {
      velocity.setDx(1);
   }
}

void BigRock::draw()
{
   if (alive)
   {
      drawLargeAsteroid(getPoint(), rotate);
   }
}

void MediumRock::draw()
{
   if (alive)
   {
      drawMediumAsteroid(getPoint(), rotate);
   }
}
void SmallRock::draw()
{
   if (alive)
   {
      drawSmallAsteroid(getPoint(), rotate);
   }
}








