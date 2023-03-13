#pragma once

#include "Entity.h"
#include "Bullet.hpp"


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

    //void SetBulletList(std::vector<Bullet*> Bullet_list) {bullet_list = Bullet_list;}
    void SetBullet (SDL_Event &e);
    std::vector<Bullet*> GetBulletList() const {return bullet_list;}
    void MakeBullet( SDL_Renderer* ren,SDL_Texture* text);
    //void RemoveBullet(const int& idx);


private:

    vector<Bullet*> bullet_list;

};
