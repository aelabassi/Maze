#include "window.h"

/**
 * main - Entry point
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    SDL_instance instance;

    if (create_window(&instance))
        return (1);


    while ("c is awesome")
    {
       SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
        SDL_RenderClear(instance.renderer);
        /* Drawing some stuff*/
        draw_maze(&instance);
        SDL_RenderPresent(instance.renderer);
    
    }


    return (0);
}