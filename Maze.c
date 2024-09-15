#include "window.h"
#include "game.h"
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
        handleInput(&isGameRunning);
        updateFrame();
        renderGame(&instance);

    }
    destroyWindow(&instance);
    


    return (0);
}