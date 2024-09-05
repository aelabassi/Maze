#include "Entity.hh"

Entity::Entity(float x, float y, SDL_Texture *texture)
: x(x), y(y), texture(texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;

}
Entity::~Entity()
{
}
