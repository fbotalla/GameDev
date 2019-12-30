#include "bullet.h"
#include "uiDraw.h"

#include <cmath>

void Bullet::draw()
{
   if (alive)
   {
      drawDot(point);
   }
}


void Bullet::fire(Point point, float angle)
{
  this->point = point;
  velocity.setDx (-cos(M_PI / 180.0 * angle) * BULLET_SPEED);
  velocity.setDy (sin(M_PI / 180.0 * angle) * BULLET_SPEED);

   alive = true;
}
