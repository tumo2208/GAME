#pragma once

#include "Entity.h"


const int BULLET_WIDTH = 20;
const int BULLET_HEIGHT = 60;
const int BULLET_SPEED = 8;
const int EGG_SPEED = 5;


class Bullet : public Entity
{

public:

    Bullet();
    ~Bullet();

    void BulletMove(const int& x_border, const int& y_border);
    void EggMove(const int& x_border, const int& y_border);

    bool get_is_move() const {return isMove;}
    void set_is_move(bool is_move) {isMove = is_move;}
    void SetWidthHeight(const int& width, const int& height) {rect.w = width; rect.h = height;};

    /*void set_x_val(const int& x) {xpos = x;}
    void set_y_val(const int& y) {ypos = y;}

    int get_x_val() const {return xpos;}
    int get_y_val() const {return ypos;}*/


private:

    int xpos;
    int ypos;

    bool isMove;

};

