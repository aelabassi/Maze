#include "game.hh"
/**
 * main - Entry point
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    Game game;
    game.init("Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game.running())
    {
        game.handleEvents();
        game.update();
        game.render();
    }
    game.clean();
    return (0);


}
