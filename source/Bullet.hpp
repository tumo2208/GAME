#pragma once

#include "source/Game.hpp"
#include "source/Entity.h"


const int BULLET_WIDTH = 20;
const int BULLET_HEIGHT = 60;
const int BULLET_SPEED = 5;


class Bullet : public Entity
{
public:

    Bullet();
    ~Bullet();
    void HandleMove(const int& x_border, const int& y_border);

    bool get_is_move() const {return is_move_;}
    void set_is_move(bool is_move) {is_move_ = is_move;}
    void SetWidthHeight(const int& widht, const int& height) {rect_.w = widht; rect_.h = height;};

    void set_x_val(const int& val) {x_val_ = val;}
    void set_y_val(const int& val) {y_val_ = val;}

    int get_x_val() const {return x_val_;}
    int get_y_val() const {return y_val_;}


private:
    int x_val_;
    int y_val_;

    bool is_move_;
};

