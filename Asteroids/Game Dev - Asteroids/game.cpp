/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

/****************************************
 * GAME CONSTRUCTOR
 ****************************************/
Game::Game(Point tl, Point br)
   : topLeft(tl), bottomRight(br), ship(0)
   {
   shots = 0;
   score = 0;
   Rock *rock = NULL;
   }

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   Rock *rock = NULL;
   if (rock != NULL)
   {
      delete rock;
   }
   rock = NULL;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
   ship.advance();
   advanceBullets();
   advanceRock();
   handleWrap();
   handleCollisions();
   cleanUpZombies();
   isInvincible();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
         bullets[i].advance();  
   }
}

/**************************************************************************
 * GAME :: ADVANCE ROCK
 * 1. If there is a rock, and it's alive, advance it
 **************************************************************************/
void Game::advanceRock()
{
   if (rock.empty())
      createRocks();
   else
      for (vector <Rock*> ::iterator it = rock.begin(); it != rock.end(); ++it)
         (*it)->advanceRock();
}

// You may find this function helpful...
/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game::getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
         obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
         obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();

      float distSquared = (xDiff * xDiff) + (yDiff * yDiff);

      distMin = min(distMin, distSquared);
   }

   return sqrt(distMin);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a rock and a bullet, rock and ship
 **************************************************************************/
void Game::handleCollisions()
{
//for bullets with rocks
if (ship.isAlive())
{
   for (int r = 0; r < rock.size(); r++)
   {
      Rock rocks = *rock[r];
      Point newPoint = rock[r]->getPoint();
      for (int i = 0; i < bullets.size(); i++)
      {
         if (bullets[i].isAlive())
         {
            if (rock[r]->isAlive())
            {
               if (getClosestDistance(bullets[i], rocks) <= fabs((bullets[i].getSize() + rock[r]->getSize())))
               {
                  createRock(rock[r]->getType(), rocks, newPoint);
                  rock[r]->kill();
                  bullets[i].kill();

                  score++;
               }
            }
         }
      }
   }

   //for ship with rocks
   for (int r = 0; r < rock.size(); r++)
   {
      Rock rocks = *rock[r];

      {
         if (getClosestDistance(rocks, ship) <= fabs((ship.getSize() + rock[r]->getSize())))
         {
            Point newPoint = rock[r]->getPoint();
            createRock(rock[r]->getType(), rocks, newPoint);
            if (!isInvincible())
            {
               ship.kill();
            }
            rock.erase(rock.begin() + r);
            score++;
         }
      }
   }
}
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate rock)
 **************************************************************************/
void Game::cleanUpZombies()
{
   Rock* rock = NULL;
   if (rock != NULL && !rock->isAlive())
   {
      delete rock;
      rock = NULL;
   }

   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;

      if (!bullet.isAlive())
      {
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }


}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface & ui)
{
   if (ship.isAlive())
   {
      ship.moveShip(ui);

      if (ui.isSpace())
      {
         Bullet newBullet;
         newBullet.fire(ship.getPoint(), ship.getAngle());
         bullets.push_back(newBullet);
         shots++;
      }
      if (ui.isDown())
      {
         changeGun(typeGun);
      }
   }
}



/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface & ui)
{
   //ship drawing
   ship.draw();

   //rocks drawing
   for (int i = 0; i < rock.size(); i++) 
   {
      rock[i]->draw();
   }

   //bullets drawing
   if (typeGun == 0)
   {
      for (int i = 0; i < bullets.size(); i++)
      {
         bullets[i].draw();
      }
   }
   else
   {
      for (int i = 0; i < bullets.size(); i++)
      {
         bullets[i].draw2();
      }
   }

   Point shotLocation;
   shotLocation.setX(topLeft.getX() + 360);
   shotLocation.setY(topLeft.getY() - 5);

   Point shotText;
   shotText.setX(topLeft.getX() + 350);
   shotText.setY(topLeft.getY() - 30);
   drawText(shotText, "N.Bullets");

   drawNumber(shotLocation, shots);

   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   drawNumber(scoreLocation, score);

   Point gunText;
   gunText.setX(topLeft.getX() + 320);
   gunText.setY(topLeft.getY() - 50);
   drawText(gunText, "Gun type");

   Point gunLocation;
   gunLocation.setX(topLeft.getX() + 375);
   gunLocation.setY(topLeft.getY() - 40);
   drawNumber(gunLocation, typeGun);
}


void Game::handleWrap()
{

   ship.wrap(topLeft, bottomRight);

   for (int i = 0; i < rock.size(); i++)
   {
      rock[i]->wrap(topLeft, bottomRight);
   }
}


/**************************************************************************
 * GAME :: CREATE ROCK
 * Create 5 rocks
 **************************************************************************/
void Game::createRocks()
{
   for (int i = 0; i < 5; i++)
   {
      Rock* newRock = NULL;
      newRock = new BigRock();
      rock.push_back(newRock);
   }
}


void Game::createRock(int type, Rock rocks, Point point) {

   if (type == 1)
   {
      //1st medium asteroid
      Rock *newRock1 = NULL;
      newRock1 = new MediumRock();
      newRock1->setPoint(point);
      rock.push_back(newRock1);

      //2nd medium asteroid
      Rock* newRock2 = NULL;
      newRock2 = new MediumRock();
      newRock2->setPoint(point);
      rock.push_back(newRock2);
     
      //small asteroid
      Rock* newRock3 = NULL;
      newRock3 = new SmallRock();
      newRock3->setPoint(point);
      rock.push_back(newRock3);
   }
   else if (type == 2) 
   {
      //1st small asteroid
      Rock* newRock1 = NULL;
      newRock1 = new SmallRock();
      newRock1->setPoint(point);
      rock.push_back(newRock1);
  
      //2nd small asteroid
      Rock* newRock2 = NULL;
      newRock2 = new SmallRock();
      newRock2->setPoint(point);
      rock.push_back(newRock2);
   }

}

bool Game::isInvincible()
{
   if (shots % 5 == 0 &&  shots >1 && score < 5)
   {
      Point shotText;
      shotText.setX(topLeft.getX() + 170);
      shotText.setY(topLeft.getY() - 30);
      drawText(shotText, "You are invincible!");
      ship.drawInvincible();
      return true;
   }
   else
   {
      return false;
   }
}

int Game::changeGun(int &typeGun)
{
      if (typeGun == 0)
      {
         typeGun++;
      }
      else
      {
         typeGun--;
      }
      return typeGun;
}
