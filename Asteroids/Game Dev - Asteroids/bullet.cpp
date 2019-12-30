#include "bullet.h"


// Put your bullet methods here

Bullet::Bullet() 
{
   setSize(2);
}

void Bullet::draw()
{
   if (alive)
   {
      drawDot(getPoint());
   }
}

void Bullet::draw2()
{
   if (alive)
   {
      drawLander(getPoint());
      setSize(4);
   }
}



void Bullet::fire(Point point, float angle)
{
   this->point = point;
   velocity.setDx(-sin(M_PI / 180.0 * angle) * BULLET_SPEED);
   velocity.setDy(cos(M_PI / 180.0 * angle) * BULLET_SPEED);

   alive = true;
}