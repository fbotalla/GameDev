#include "bird.h"
#include "uiDraw.h"

StandardBird::StandardBird(const Point &point) : Bird(point)
{
   float dx = random(3, 6);
   float dy = random(0, 4);

   if (point.getY() > 0)
      dy *= -1;

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);
}

void StandardBird::draw()
{
   if (alive)
      drawLander(point);
}

int StandardBird::hit()
{
   kill();
   return 1;
}


ToughBird::ToughBird(const Point &point) : Bird(point)
{
   float dx = random(2, 4);
   float dy = random(0, 4);

   if (point.getY() > 0)
      dy *= -1;

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);
}

void ToughBird::draw()
{
   if (alive)
      drawToughBird(point, 15, life);
}

int ToughBird::hit()
{
   --life;
   if (life < 1)
   {
      kill();
      return 3;
   }
   return 1;
}

SacredBird::SacredBird(const Point &point) : Bird(point)
{
   float dx = random(3, 6);
   float dy = random(0, 4);

   if (point.getY() > 0)
      dy *= -1;

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);
}

void SacredBird::draw()
{
   if (alive)
      drawSacredBird(point, 15);
}

int SacredBird::hit()
{
   kill();
   return -10;
}