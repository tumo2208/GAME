#include "Chicken.hpp"

Chicken::Chicken()
{

    rect.x = SCREEN_WIDTH / 2;
    rect.y = 0;
    rect.h = CHICKEN_HEIGHT;
    rect.w = CHICKEN_WIDTH;

    xpos = ypos = 0;
}


Chicken::~Chicken()
{

    if (egg_list.size() > 0)
    {
        for (int i = 0; i < int(egg_list.size()); i++) {
            Bullet* egg = egg_list[i];
            if (egg != NULL)
            {
                delete egg;
                egg = NULL;
            }
        }
        egg_list.clear();
    }

}


void Chicken::ChickenMove(const int& x_border, const int& y_border)
{

    rect.y += CHICKEN_SPEED;
    if (rect.y > SCREEN_HEIGHT) {
        rect.y = 0;
        rect.x = random();
    }

}


void Chicken::EggBullet (Bullet* egg)
{

    if (egg != NULL)
    {
        egg->set_is_move(true);
        egg->SetWidthHeight(20, 20);
        egg->SetRect(rect.x + rect.w / 2 - 10, rect.y + rect.h);
        egg_list.push_back(egg);
    }

}


void Chicken::MakeEgg (SDL_Renderer* ren, SDL_Texture* text)
{

    for (int i = 0; i < int(egg_list.size()); i++)
    {

        Bullet* egg = egg_list[i];
        if (egg != NULL)
        {
            if (egg->get_is_move()) {
                egg->Show(text, ren);
                egg->EggMove(SCREEN_WIDTH, SCREEN_HEIGHT);
            }
            else {
                egg->set_is_move(true);
                egg->SetRect(rect.x + rect.w / 2 - 10, rect.y + rect.h);
            }
        }

    }

}
