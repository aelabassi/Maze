#include "game.h"
int isGameRunning;
int TicksLastFrame;
Player player;

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
     WallTexturesready();
 }

 /**
  * updateFrame - update the frame
  */
    void updateFrame(void)
 {
     float DeltaTime;
     int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

     if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
     {
         SDL_Delay(timeToWait);
     }
     DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;

     TicksLastFrame = SDL_GetTicks();

     movePlayer(DeltaTime);
     castAllRays();
 }

 /*
 * renderGame - render the game
  * @instance: The instance to render
  */
 void renderGame(SDL_instance *instance)
 {
        clearColorBuffer(0xFF000000);
        //renderWall();
        renderMap();
        renderRays();
        renderPlayer();
        renderColorBuffer(instance);
 }
 /**
  * main - Entry point
  * Return: 0 on success, 1 on failure
  */
 int main(void)
 {
     SDL_instance instance;
     isGameRunning = create_window(&instance);

     if (isGameRunning != 0)
         return (1);
     setupPlayer();
     while (isGameRunning == 0)
     {
         handleInput();
         updateFrame();
         renderGame(&instance);

     }
     destroyWindow(&instance);
     freeWallTextures();



     return (0);
 }
