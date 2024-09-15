#ifndef WINDOW_H
#define WINDOW_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>

typedef uint32_t color_t;
extern int isGameRunning;

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




/* Functions-variables-structs for draw */

int initializeWindow(void);
void destroyWindow(SDL_instance *instance);
void clearColorBuffer(color_t color);
void render_game(void);
void renderColorBuffer(SDL_instance *instance);
void drawPixel(int x, int y, color_t color);
void drawRect(int x, int y, int width, int height, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);



int create_window(SDL_instance *instance);
void draw_maze(SDL_instance *instance);
int poll_events();



#endif /* WINDOW_H */
