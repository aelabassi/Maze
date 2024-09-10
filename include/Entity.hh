#pragma once
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "Math.hh"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


/**
 * @brief Base class for all entities in the game
 * @file Entity.hh
 * @class Entity
 * @author EL Abassi Abderrazaq
 */
class Entity {

private:
    Vector2D position;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
public:
    Entity(Vector2D pos, SDL_Texture* texture);
    ~Entity();

    Vector2D& getPosition() { return position; };
    SDL_Texture *getTexture() const { return texture; };
    SDL_Rect getCurrentFrame() const { return currentFrame; };

};
