#include "game.h"
/**
 * setupPlayer - set up the player
 */
 void setupPlayer(void)
 {
     player.x = SCREEN_WIDTH / 2;
     player.y = SCREEN_HEIGHT / 2;
     player.width = 2;
     player.height = 2;
     player.turnDirection = 0;
     player.walkDirection = 0;
     player.rotationAngle = PI / 2;
     player.walkSpeed = 100;
     player.turnSpeed = 45 * (PI / 180);
 }

 /**
  * updateFrame - update the frame
  */
    void updateFrame(void)
 {
        int TicksLastFrame = SDL_GetTicks();
     float DeltaTime;
     int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

     if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
     {
         SDL_Delay(timeToWait);
     }
     DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;

     TicksLastFrame = SDL_GetTicks();

     movePlayer(DeltaTime);
 }

 /*
 * renderGame - render the game
  * @instance: The instance to render
  */
 void renderGame(SDL_instance *instance)
 {
        clearColorBuffer(0xFF000000);
        renderMap();
        renderPlayer();
        renderColorBuffer(instance);
 }
