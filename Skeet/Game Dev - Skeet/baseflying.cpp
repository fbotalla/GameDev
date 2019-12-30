#include "baseflying.h"
#include "uiDraw.h"

void BaseFlying::setPoint(Point point)
{
   this->point = point;
}

void BaseFlying::setVelocity(Velocity velocity)
{
   this->velocity = velocity;
}

void BaseFlying::advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
}


BaseFlying::~BaseFlying()
{
}
