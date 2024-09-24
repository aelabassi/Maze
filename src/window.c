#include "window.h"
#include "game.h"

static color_t *colorBuffer;
static SDL_Texture *colorBufferTexture;
/**
 * create_window - Create a window with a renderer
 * Return: 0 on success, 1 on failure
 */
bool create_window(SDL_instance *instance)
{
    SDL_DisplayMode display_mode;
	int fullScreenWidth, fullScreenHeight;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (false);
	}
	SDL_GetCurrentDisplayMode(0, &display_mode);
	fullScreenWidth = display_mode.w;
	fullScreenHeight = display_mode.h;
	instance->window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		fullScreenWidth,
		fullScreenHeight,
		SDL_WINDOW_BORDERLESS
	);
	if (!instance->window)
	{
		fprintf(stderr, "Error creating SDL window.\n");
		return (false);
	}
	instance->renderer = SDL_CreateRenderer(instance->window, -1, 1);
	if (!instance->renderer)
	{
		fprintf(stderr, "Error creating SDL renderer.\n");
		return (false);
	}
	SDL_SetRenderDrawBlendMode(instance->renderer, SDL_BLENDMODE_BLEND);

	/* allocate the total amount of bytes in memory to hold our colorbuffer */
	colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

	/* create an SDL_Texture to display the colorbuffer */
	colorBufferTexture = SDL_CreateTexture(instance->renderer, SDL_PIXELFORMAT_RGBA32,
		SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	return (true);
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

