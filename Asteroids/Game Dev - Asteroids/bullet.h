#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40
#define M_PI 3.14159265358979323846


#include "flyingObject.h"

//class bullet is a flying objet
class Bullet : public FlyingObject
{

public:
   Bullet();
   void draw();
   void draw2();
   void fire(Point point, float angle);

};

#endif



