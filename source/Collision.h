#pragma once

#include <SDL.h>


class Collision
{

public:

    Collision() {}
    ~Collision() {};

    bool VaCham (const SDL_Rect& recA, const SDL_Rect& recB);

};


