#ifndef BIRD_H
#define BIRD_H
#include "baseflying.h"

class Bird : public BaseFlying
{

public:
   Bird(const Point &point)
   {
      alive = true;
      setPoint(point);
   }

   virtual void draw() = 0;
   virtual int hit() = 0;
};


class StandardBird : public Bird
{
public:
   StandardBird(const Point &point);
   virtual void draw();
   virtual int hit();

};

class ToughBird : public Bird
{
private:
   int life = 3;
public:
   ToughBird(const Point&point);
   virtual void draw();
   virtual int hit();
};


class SacredBird : public Bird
{
public:
   SacredBird(const Point &point);
   virtual void draw();
   virtual int hit();
};
#endif