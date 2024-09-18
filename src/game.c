#include "game.h"
#include "window.h"

int isGameRunning = 1;
int TicksLastFrame;
Player player;

/**
 * setupPlayer - set up the player
 */
 void setupPlayer(void)
 {
     player.x = SCREEN_WIDTH / 2;
     player.y = SCREEN_HEIGHT / 2;
     player.width = 1;
     player.height = 30;
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
 void renderGame()
 {
        clearColorBuffer(0xFF000000);
        renderWall();
        renderMap();
        renderRays();
        renderPlayer();
        renderColorBuffer();
 }
 /**
  * main - Entry point
  * Return: 0 on success, 1 on failure
  */
 int main(void)
 {

     isGameRunning = create_window();
 
     setupPlayer();
    
     while (isGameRunning)
     {
         handleInput();
         updateFrame();
         renderGame();

     }
     destroyWindow();
     freeWallTextures();



     return (0);
 }
