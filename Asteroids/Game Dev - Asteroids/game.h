/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
#include "bullet.h"
#include "rocks.h"

#include <vector>


#define CLOSE_ENOUGH 15

class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();

   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);

   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();

   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);

private:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;

   int score;
   int shots;
   int typeGun;

   bool invincible = false;

   Ship ship;
   std::vector<Bullet> bullets;
   std::vector <Rock*> rock;

   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   
   void advanceBullets();
   void advanceRock();
 
   float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
   void handleCollisions();
   void cleanUpZombies();

   void handleWrap();
  
   void createRock(int type,Rock rocks, Point point);
   void createRocks();

   bool isInvincible();
   int changeGun(int &typeGun);
};


#endif
