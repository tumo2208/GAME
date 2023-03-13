#include "Entity.h"


void Entity::Show(SDL_Texture* text, SDL_Renderer* ren)
{

    SDL_RenderCopy(ren, text, NULL, &rect);

}
