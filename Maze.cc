#include "game.hh"
#include <vector>
#include "Utils.hh"
/**
 * main - Entry point
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    Game game;
    game.init("Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    Entity entity0(Vector2D(0,0), game.loadTexture("../assets/ground_grass_1.png"));
    Entity entity1(Vector2D(30,0), game.loadTexture("../assets/ground_grass_1.png"));
    Entity entity2(Vector2D(30,30), game.loadTexture("../assets/ground_grass_1.png"));
    Entity entity3(Vector2D(30, 60), game.loadTexture("../assets/ground_grass_1.png"));
    std::vector<Entity> entities;
    entities.push_back(entity0);
    entities.push_back(entity1);
    entities.push_back(entity2);
    entities.push_back(entity3);

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = Utils::hireTimeInSeconds();

    while (game.running())
    {
        float newTime = Utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;
        currentTime = newTime;
        accumulator += frameTime;
        while (accumulator >= timeStep) {
            game.handleEvents();
            // game.update();
            game.clear();
            for (auto &entity: entities) {
                game.render_texture(entity);
            }
            accumulator -= timeStep;
        }
        float alpha = accumulator / timeStep;
        std::cout << "percentage of time left in the accumulator: " << alpha << std::endl;
        game.display();
        std::cout << Utils::hireTimeInSeconds() << std::endl;
    }
    game.clean();
    return (0);


}
