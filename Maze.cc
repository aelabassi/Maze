#include "game.hh"
/**
 * main - Entry point
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    Game game;
    game.init("Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    Entity platform0(100, 50, game.loadTexture("../assets/ground_grass_1.png"));
    while (game.running())
    {
        game.handleEvents();
        game.update();
        game.clear();
        game.render_texture(platform0);
        game.display();
    }
    game.clean();
    return (0);


}
