#include "window.h"
#include "game.h"

static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
/**
 * create_window - Create a window with a renderer
 * @instance: The instance to create
 * Return: 0 on success, 1 on failure
 */
int create_window(SDL_instance *instance)
{
    SDL_DisplayMode display;
    int fullScreenWidth, fullScreenHeight;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
    }
    SDL_GetCurrentDisplayMode(0, &display);
    fullScreenWidth = display.w;
    fullScreenHeight = display.h;
	instance->window = SDL_CreateWindow("SDL2 Window",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, fullScreenWidth, fullScreenHeight, 0);
	if (!instance->window)
    {
		fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
    }

	instance->renderer = SDL_CreateRenderer(instance->window, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 255);
    SDL_RenderPresent(instance->renderer);

	if (!instance->renderer)
    {
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
        SDL_Quit();
		return (1);
    }

    colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);
    colorBufferTexture = SDL_CreateTexture(instance->renderer, SDL_PIXELFORMAT_RGBA32,
                                           SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	return (0);
}

/**
 * DestroyWindow - Destroy a window with a renderer
 *@instance: The instance to destroy
 */
void destroyWindow(SDL_instance *instance)
{
    free(colorBuffer);
    SDL_DestroyTexture(colorBufferTexture);
    SDL_DestroyRenderer(instance->renderer);
    SDL_DestroyWindow(instance->window);
    SDL_Quit();
}

/**
 * clearColorBuffer - clear the color buffer
 * @color: color to clear with
 */
void clearColorBuffer(color_t color)
{
    int i;
    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
        colorBuffer[i] = color;
}

/**
 * renderColorBuffer - render buffer for every frame
 *@instance: The instance to render
*/

void renderColorBuffer(SDL_instance *instance)
{
    SDL_UpdateTexture(
            colorBufferTexture,
            NULL,
            colorBuffer,
            (int)(SCREEN_WIDTH * sizeof(color_t))
    );
    SDL_RenderCopy(instance->renderer, colorBufferTexture, NULL, NULL);
    SDL_RenderPresent(instance->renderer);
}

/**
 * drawPixel - assign a color to each pixel
 * @x: x pixel coordinate
 * @y: y pixel coordinate
 * @color: pixel color
*/

void drawPixel(int x, int y, color_t color)
{
    colorBuffer[(SCREEN_WIDTH * y) + x] = color;
}

