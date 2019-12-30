#include "ship.h"

// Put your ship methods here
void Ship::draw()
{
   if (alive)
   {
      drawShip(getPoint(), angle, false);
   }
}

void Ship::drawInvincible()
{
   if (alive)
   {
      drawShip(getPoint(), angle, true);
   }
}
   
void Ship::moveShip(const Interface & ui)
{
      if (ui.isUp())
      {
         velocity.setDx(-sin(M_PI / 180.0 * angle) * 2);
         velocity.setDy(cos(M_PI / 180.0 * angle) * 2);
         advance();
      }

      if (ui.isLeft())
      {
         angle += ROTATE_AMOUNT;
      }

      if (ui.isRight())
      {
         angle -= ROTATE_AMOUNT;
      }
} 