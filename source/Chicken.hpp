#pragma once

#include "Entity.h"
#include "Bullet.hpp"


const int CHICKEN_WIDTH = 72;
const int CHICKEN_HEIGHT = 63;
const int CHICKEN_SPEED = 3;
const int NUMBER_OF_CHICKEN = 3;


class Chicken : public Entity
{

public:

    Chicken();
    ~Chicken();

    void ChickenMove(const int& x_border, const int& y_border);
    void EggBullet (Bullet* bullet);
    void MakeEgg (SDL_Renderer* ren, SDL_Texture* text);

    /*void set_x_val(const int& x) {xpos = x;}
    void set_y_val(const int& y) {ypos = y;}

    int get_x_val() const {return xpos;}
    int get_y_val() const {return ypos;}*/


private:

    int xpos, ypos;

    vector <Bullet*> egg_list;

};

