###############################################################
# Program:
#     Project 09, Skeet
#     Brother Alvey, CS165
# Author:
#     Fabrizio Botalla
# Summary:
#	  This is a full on working skeet game
# Above and Beyond
#
#	  I have put a count for bullets on the right
#	  top corner of the screen. This count resets at
#	  every bird that is being sent in. I put a condition
#	  to where the user can only fire 10 bullets at each
#	  bird.
#
#	  The standard bird now look like a lander.
#
#	  Each time a bird gets hit, we can notice red lines which
#	  are a visual of the bird being hit along with the word "HIT"
#
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o baseflying.o velocity.o bird.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o bullet.o baseflying.o velocity.o bird.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
baseflying.o: baseflying.cpp baseflying.h point.h
	g++ -c baseflying.cpp

bullet.o: bullet.h bullet.cpp baseflying.h velocity.h uiDraw.h
	g++ -c bullet.cpp

velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

bird.o: bird.h bird.cpp baseflying.h point.h velocity.h uiDraw.h
	g++ -c bird.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
