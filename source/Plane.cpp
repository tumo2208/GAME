#include "source/Plane.hpp"


const Uint8* plane_getkb = SDL_GetKeyboardState (NULL);


Plane::Plane()
{

    rect_.x = PLANE_START_X;
    rect_.y = PLANE_START_Y;
    rect_.h = PLANE_HEIGHT;
    rect_.w = PLANE_WIDTH;

}


Plane::~Plane()
{

}


void Plane::HandleInputPlane(SDL_Event &e)
{

    SDL_PollEvent(&e);
    if (plane_getkb[SDL_SCANCODE_W] || plane_getkb[SDL_SCANCODE_UP]) {
        rect_.y = max(0, rect_.y - PLANE_SPEED);
    }
    if (plane_getkb[SDL_SCANCODE_S] || plane_getkb[SDL_SCANCODE_DOWN]) {
        rect_.y = min(SCREEN_HEIGHT - PLANE_HEIGHT, rect_.y + PLANE_SPEED);
    }
    if (plane_getkb[SDL_SCANCODE_A] || plane_getkb[SDL_SCANCODE_LEFT]) {
        rect_.x = max(0, rect_.x - PLANE_SPEED);
    }
    if (plane_getkb[SDL_SCANCODE_D] || plane_getkb[SDL_SCANCODE_RIGHT]) {
        rect_.x = min(SCREEN_WIDTH - PLANE_WIDTH, rect_.x + PLANE_SPEED);
    }

    if(/*e.type == SDL_MOUSEBUTTONDOWN*/ e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_j)
    {
        Bullet* p_bullet = new Bullet();
        if (e.key.keysym.sym == SDLK_j)
        {
          p_bullet->SetWidthHeight(BULLET_WIDTH, BULLET_HEIGHT);

        }

        p_bullet->SetRect(this->rect_.x + this->rect_.w / 2 - 10, this->rect_.y - 20);
        p_bullet->set_is_move(true);
        p_bullet->set_y_val(BULLET_SPEED);
        p_bullet_list_.push_back(p_bullet);
    }

}


void Plane::plane_display(SDL_Texture* texture, SDL_Renderer* renderer)
{

    SDL_RenderCopy (renderer, texture, NULL, &rect_);

}


void Plane::MakeBullet(SDL_Renderer* renderer,SDL_Texture* texture_bullet)
{
    for (int i = 0; i < p_bullet_list_.size(); i++)
    {
        Bullet* p_bullet_ = p_bullet_list_[i];
        if (p_bullet_ != NULL)
        {
            if (p_bullet_->get_is_move())
            {
                p_bullet_->Show(texture_bullet,renderer);
                p_bullet_->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
            }
            else
            {
                if (p_bullet_ != NULL)
                    {
                      p_bullet_list_.erase(p_bullet_list_.begin() + i);
                      i--;
                      delete p_bullet_;
                      p_bullet_ = NULL;
                    }
            }
        }
    }
}


void Plane::RemoveBullet(const int& idx)
{
    for (int i = 0; i < p_bullet_list_.size(); i++)
    {
        if (idx < p_bullet_list_.size())
        {
            Bullet* p_bullet = p_bullet_list_[idx];
            p_bullet_list_.erase(p_bullet_list_.begin() + idx);

            if (p_bullet != NULL)
            {
                delete p_bullet;
                p_bullet = NULL;
            }
        }
    }
}





