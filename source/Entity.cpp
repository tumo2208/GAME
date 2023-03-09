#include "source/Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}


void Entity::Show(SDL_Texture* texture_,SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer,texture_,NULL,&rect_);
}
