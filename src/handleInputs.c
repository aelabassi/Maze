#include "window.h"
#include "game.h"

/**
 * poll_events - add events
 * Return: 1 on quit or keypress, 0 otherwise
 */
int poll_events(void)
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
/**
 * SDL_KEYDOWN_FUNC - process input when a key is down
 * @event: union that contains structures for the different event types
*/

void SDL_KEYDOWN_FUNC(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_ESCAPE)
        isGameRunning = 1;
    if (event.key.keysym.sym == SDLK_UP)
        player.walkDirection = +1;
    if (event.key.keysym.sym == SDLK_DOWN)
        player.walkDirection = -1;
    if (event.key.keysym.sym == SDLK_RIGHT)
        player.turnDirection = +1;
    if (event.key.keysym.sym == SDLK_LEFT)
        player.turnDirection = -1;
    if (event.key.keysym.sym == SDLK_w)
        player.walkDirection = +1;
    if (event.key.keysym.sym == SDLK_s)
        player.walkDirection = -1;
    if (event.key.keysym.sym == SDLK_a)
        player.turnDirection = -1;
    if (event.key.keysym.sym == SDLK_d)
        player.turnDirection = +1;
}

/**
 * SDL_KEYUP_FUNC - process input when a key is up
 * @event: union that contains structures for the different event types
*/

void SDL_KEYUP_FUNC(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_UP)
        player.walkDirection = 0;
    if (event.key.keysym.sym == SDLK_DOWN)
        player.walkDirection = 0;
    if (event.key.keysym.sym == SDLK_RIGHT)
        player.turnDirection = 0;
    if (event.key.keysym.sym == SDLK_LEFT)
        player.turnDirection = 0;
    if (event.key.keysym.sym == SDLK_w)
        player.walkDirection = 0;
    if (event.key.keysym.sym == SDLK_s)
        player.walkDirection = 0;
    if (event.key.keysym.sym == SDLK_a)
        player.turnDirection = 0;
    if (event.key.keysym.sym == SDLK_d)
        player.turnDirection = 0;
}

/**
 * handleInput - process input from the keyboard
 *
*/
void handleInput(void)
{
    SDL_Event event;

    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
        isGameRunning = 0;
    else if (event.type == SDL_KEYDOWN)
        SDL_KEYDOWN_FUNC(event);
    else if (event.type == SDL_KEYUP)
        SDL_KEYUP_FUNC(event);
}
