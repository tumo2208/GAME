#pragma once

#include "source/Game.hpp"
#include "source/Entity.h"
#include "source/Bullet.hpp"


const int PLANE_WIDTH = 100;
const int PLANE_HEIGHT = 90;
const int PLANE_START_X = 630;
const int PLANE_START_Y = 600;
const int PLANE_SPEED = 5;


class Plane : public Entity
{

public:

    Plane();
    ~Plane();

    void HandleInputPlane(SDL_Event &e);
    void plane_display (SDL_Texture* texture, SDL_Renderer* renderer);

    void SetBulletList(std::vector<Bullet*> bullet_list) {p_bullet_list_ = bullet_list;}
    std::vector<Bullet*> GetBulletList() const {return p_bullet_list_;}
    void MakeBullet( SDL_Renderer* renderer,SDL_Texture* texture_bullet);
    void RemoveBullet(const int& idx);


private:

    vector<Bullet*> p_bullet_list_;

};
