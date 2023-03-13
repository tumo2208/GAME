#include "Plane.hpp"


const Uint8* getkb = SDL_GetKeyboardState (NULL);


Plane::Plane()
{

    rect.x = PLANE_START_X;
    rect.y = PLANE_START_Y;
    rect.h = PLANE_HEIGHT;
    rect.w = PLANE_WIDTH;

}


Plane::~Plane()
{

}


void Plane::HandleInputPlane(SDL_Event &e)
{

    if (getkb[SDL_SCANCODE_W] || getkb[SDL_SCANCODE_UP]) {
        rect.y = max(0, rect.y - PLANE_SPEED);
    }
    if (getkb[SDL_SCANCODE_S] || getkb[SDL_SCANCODE_DOWN]) {
        rect.y = min(SCREEN_HEIGHT - PLANE_HEIGHT, rect.y + PLANE_SPEED);
    }
    if (getkb[SDL_SCANCODE_A] || getkb[SDL_SCANCODE_LEFT]) {
        rect.x = max(0, rect.x - PLANE_SPEED);
    }
    if (getkb[SDL_SCANCODE_D] || getkb[SDL_SCANCODE_RIGHT]) {
        rect.x = min(SCREEN_WIDTH - PLANE_WIDTH, rect.x + PLANE_SPEED);
    }

}


void Plane::SetBullet (SDL_Event &e)
{

    //SDL_PollEvent(&e);

    if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_j)
    {
        Bullet* bullet = new Bullet();

        bullet->SetWidthHeight(BULLET_WIDTH, BULLET_HEIGHT);

        bullet->SetRect(this->rect.x + this->rect.w / 2 - BULLET_WIDTH / 2, this->rect.y - BULLET_HEIGHT / 2);
        bullet->set_is_move(true);
        //bullet->set_y_val(BULLET_SPEED);
        bullet_list.push_back(bullet);

    }

}


void Plane::MakeBullet(SDL_Renderer* ren,SDL_Texture* text)
{
    for (int i = 0; i < int(bullet_list.size()); i++)
    {
        Bullet* p_bullet_ = bullet_list[i];
        if (p_bullet_ != NULL)
        {
            if (p_bullet_->get_is_move())
            {
                p_bullet_->Show(text,ren);
                p_bullet_->BulletMove(SCREEN_WIDTH, SCREEN_HEIGHT);
            }
            else
            {
                  bullet_list.erase(bullet_list.begin() + i);
                  i--;
                  delete p_bullet_;
                  p_bullet_ = NULL;
            }
        }
    }
}


/*void Plane::RemoveBullet(const int& idx)
{
    for (int i = 0; i < bullet_list.size(); i++)
    {
        if (idx < bullet_list.size())
        {
            Bullet* p_bullet = bullet_list[idx];
            bullet_list.erase(bullet_list.begin() + idx);

            if (p_bullet != NULL)
            {
                delete p_bullet;
                p_bullet = NULL;
            }
        }
    }
}*/





