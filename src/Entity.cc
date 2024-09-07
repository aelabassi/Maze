#include "Entity.hh"

Entity::Entity(Vector2D pos, SDL_Texture *texture)
:position(pos) , texture(texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;

}
Entity::~Entity()
{
}
