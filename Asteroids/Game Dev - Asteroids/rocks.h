#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"

// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
protected:
   float rotate = 0;
   int type;
public:
   Rock();
   virtual void advanceRock() {}
   int getType() const { return type; }
   void setType(int t) { this->type = t; }
};


//   BigRock
class BigRock : public Rock
{
public:
   BigRock() 
   { 
   setSize(BIG_ROCK_SIZE); 
   setType(1);
   point.setX(random(-200, 200));
   point.setY(random(-200, 200)); 
   }
   void draw();
   void advanceRock()
   {
      rotate += BIG_ROCK_SPIN;
   }
};

//   MediumRock
class MediumRock : public Rock
{
public:
   MediumRock() 
   { 
    setSize(MEDIUM_ROCK_SIZE);  
    setType(2);
    velocity.setDx(random(-2, 2));
    velocity.setDy(random(-1, 1));
    if (velocity.getDx() == 0)
    {
       velocity.setDx(1);
    }
   }

   void draw();
   void advanceRock() 
   {
      rotate += MEDIUM_ROCK_SPIN;
   }
};

//   SmallRock
class SmallRock : public Rock
{
public:
   SmallRock() 
   { 
   setSize(SMALL_ROCK_SIZE); 
   setType(3);
   velocity.setDx(random(-3,3));
   velocity.setDy(random(-3,3));
   if (velocity.getDx() == 0)
    {
      velocity.setDx(3);
    }
   }

   void draw();

   void advanceRock() 
   {
      rotate += SMALL_ROCK_SPIN;
   }
};



#endif /* rocks_h */
