#include "Bullet.hpp"


Bullet::Bullet()
{
  rect.x = 0;
  rect.y = 0;
  xpos = ypos = 0;
  isMove = false;
}


Bullet::~Bullet()
{

}


void Bullet::BulletMove(const int& x_border, const int& y_border)
{
    if (isMove == true) {

        rect.y -= BULLET_SPEED;
        if (rect.y < 0)
            isMove = false;

    }
}


void Bullet::EggMove(const int& x_border, const int& y_border)
{

    rect.y += EGG_SPEED;
    if (rect.y > SCREEN_HEIGHT)
        isMove = false;

}


