#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include <SDL_image.h>
/**
 * @file game.hh
 * @brief Header file for game class: initializes the game and runs the game loop
 * @author EL Abassi Abderrazaq
 */
class Game {
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();
private:
    int cnt;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#endif // GAME_H
