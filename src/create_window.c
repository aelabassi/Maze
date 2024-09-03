#include "maze.h"

/**
 * create_window - Create a window with a renderer
 * @instance: The instance to create
 * Return: 0 on success, 1 on failure
 */
int create_window(SDL_instance *instance)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
    }

	instance->window = SDL_CreateWindow("SDL2 Window",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	if (!instance->window)
    {
		fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
    }

	instance->renderer = SDL_CreateRenderer(instance->window, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!instance->renderer)
    {
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
        SDL_Quit();
		return (1);
    }

	return (0);
}

/**
 * draw_maze - Draw the maze
 * @instance: The instance to draw
 */
void draw_maze(SDL_instance *instance)
{
    SDL_Rect rect = {0, 0, 500, 500};

    SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(instance->renderer, &rect);
}
/**
 * poll_events - add events
 * Return: 1 on quit or keypress, 0 otherwise
 */
 int poll_events()
{
     SDL_Event event;
     SDL_KeyboardEvent key;

     while(SDL_PollEvent(&event))
     {
         switch (event.type)
         {
             case SDL_QUIT:
                 return (1);
             case SDL_KEYDOWN:
                 key = event.key;
                 /* if 'ESCAPE' is passed */
                 if (key.keysym.scancode == 0x29)
                     return (1);
                 break;
         }
     }
     return (0);
}
