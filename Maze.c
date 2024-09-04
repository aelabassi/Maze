#include "window.h"
#include "game.h"
/**
 * main - Entry point
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    SDL_instance instance;
    Maze maze;

    if (create_window(&instance) != 0)
        return (1);

    init_maze(&maze);
    generate_maze(1, 1);

    while ("c is awesome")
    {
       SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 255);
        SDL_RenderClear(instance.renderer);
        if (poll_events() == 1)
            break;
        /* Drawing some stuff*/
        render_maze(&instance);
        SDL_RenderPresent(instance.renderer);
    
    }
    SDL_DestroyRenderer(instance.renderer);
    SDL_DestroyWindow(instance.window);
    SDL_Quit();
    


    return (0);
}