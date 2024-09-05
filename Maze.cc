#include "game.hh"
#include <vector>
/**
 * main - Entry point
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    Game game;
    game.init("Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    Entity entity0(0, 0, game.loadTexture("../assets/ground_grass_1.png"));
    Entity entity1(30, 0, game.loadTexture("../assets/ground_grass_1.png"));
    Entity entity2(30, 30, game.loadTexture("../assets/ground_grass_1.png"));
    Entity entity3(30, 60, game.loadTexture("../assets/ground_grass_1.png"));
    std::vector<Entity> entities;
    entities.push_back(entity0);
    entities.push_back(entity1);
    entities.push_back(entity2);
    entities.push_back(entity3);
    while (game.running())
    {
        game.handleEvents();
        game.update();
        game.clear();
        for (auto &entity : entities)
        {
            game.render_texture(entity);
        }
        game.display();
    }
    game.clean();
    return (0);


}
