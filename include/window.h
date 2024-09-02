#ifndef WINDOW_H
#define WINDOW_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>

/**
 * SDL_instance - SDL instance
 * @window: The window to create
 * @renderer: The renderer to create
 */
typedef struct SDL_instance
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL_instance;







int create_window(SDL_instance *instance);
void draw_maze(SDL_instance *instance);
int poll_events();



#endif /* WINDOW_H */
