#pragma once

#include "Game.hpp"


class Entity
{

public:

    Entity() {}
    ~Entity() {}

    void SetRect(const int& x, const int& y) {rect.x = x, rect.y = y;}
    SDL_Rect GetRect() const {return rect;}
    void Show(SDL_Texture* text,SDL_Renderer* ren);

    int random() {
        srand(time(NULL));
        return ((rand() % 38)*20);
    }


protected:

    SDL_Rect rect;
    //SDL_Texture* p_object_;

};


