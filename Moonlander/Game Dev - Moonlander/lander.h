#ifndef LANDER_H
#define LANDER_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"



#define DEFAULT_FUEL 500

class Lander
{
private:
   Point point;
   Velocity velocity;
   int input;
   int fuel;
   bool alive;
   bool landed;
   float amount;

public:
   Lander() : point(0,0), alive(true),landed(false), fuel(DEFAULT_FUEL)
   {
   }
   Point getPoint() const { return point; }
   Velocity getVelocity() const {return velocity;}
   bool isAlive() const { return alive; }
   bool isLanded() const { return landed; }
   int getFuel() const { return fuel; }
   bool canThrust();
   void setLanded(bool landed) { this->landed = landed; }
   void setAlive(bool alive) { this->alive = alive; }
   void setFuel(int fuel) { this->fuel = fuel; }
   void applyGravity(float amount);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();
   void advance();
   void draw() const;
   bool lowFuel();
   
     
};



#endif

