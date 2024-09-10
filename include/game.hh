#ifndef GAME_HH
#define GAME_HH

#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include <SDL_image.h>
#include "Entity.hh"
#include "Object.hh"

struct Properties{
    Properties(int width, int height, float X, float Y, SDL_RendererFlip flip)
     : width(width), height(height), X(X), Y(Y), flip(flip) {}
    int width, height;
    float X, Y;
    SDL_RendererFlip flip;
};

/**
 * @file game.hh
 * @brief Header file for game class: initializes the game and runs the game loop
 * @author EL Abassi Abderrazaq
 */
class Game: public Object {

public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void Update() override;
    void Draw() override;
    void clear();
    void render_texture(Entity& entity);
    void display();
    void Clean() override;
    bool running() const;
    SDL_Texture *loadTexture(const char* filepath);
private:
    int cnt;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#endif // GAME_H
