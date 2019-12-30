#ifndef BULLET_H
#define BULLET_H
#include "baseflying.h"
#include "rifle.h"
#include "velocity.h"
#include "point.h"

#include <cmath>

#define BULLET_SPEED 10.0
#define M_PI       3.14159265358979323846

class Bullet : public BaseFlying
{

public:
   virtual void draw();
   void fire(Point point, float angle);
   
};

#endif