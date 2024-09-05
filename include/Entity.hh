#pragma once
#include <SDL2/SDL.h>
#include <SDL_image.h>

/**
 * @brief Base class for all entities in the game
 * @file Entity.hh
 * @class Entity
 * @author EL Abassi Abderrazaq
 */
class Entity {

private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
public:
    Entity(float x, float y, SDL_Texture* texture);
    ~Entity();

    float getX() const { return x; };
    float getY() const { return y; };
    SDL_Texture *getTexture() const { return texture; };
    SDL_Rect getCurrentFrame() const { return currentFrame; };

};
