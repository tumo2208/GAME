#include "Game.hpp"
#include "Plane.hpp"
#include "Bullet.hpp"
#include "Chicken.hpp"
#include "Collision.h"


void Game::initSDL()
{

    win = SDL_CreateWindow(SCREEN_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    isRunning = true;

}


SDL_Texture* Game::loadIMG(const string path)
{

    SDL_Surface* loadSurface = IMG_Load (path.c_str());
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface (ren, loadSurface);
    SDL_FreeSurface(loadSurface);
    return newTexture;

}


void Game::Run()
{

    const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	SDL_Texture* background_texture = Game::loadIMG ("assets/Background_space.png");
    SDL_Texture* plane_texture = Game::loadIMG ("assets/SpaceShip.png");
    SDL_Texture* bullet_texture = Game::loadIMG ("assets/Bullet_1.png");
    SDL_Texture* chicken_texture = Game::loadIMG ("assets/Chicken_xanh.png");
    SDL_Texture* egg_texture = Game::loadIMG("assets/egg.png");

    Plane* plane = new Plane();
    Chicken* chicken_small = new Chicken[NUMBER_OF_CHICKEN];

    srand(time(NULL));

    for (int i = 0; i < NUMBER_OF_CHICKEN; i++) {

        Chicken* chicken = chicken_small + i;

        chicken->SetRect ((rand() % 38)*20, -i*300);

        Bullet* egg = new Bullet();
        chicken->EggBullet(egg);

    }

    SDL_Event e;

    int y = 0;

    while (Game::Running())
    {
        Game::EndLoop(e);

        SDL_RenderClear(ren);

        y += SCREEN_MOVE_SPEED;

        SDL_Rect background_rect1 = {0, y, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_Rect background_rect2 = {0, y - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};

        SDL_RenderCopy(ren, background_texture, NULL, &background_rect1);
        SDL_RenderCopy(ren, background_texture, NULL, &background_rect2);

        if (y >= SCREEN_HEIGHT)
            y = 0;

        plane->HandleInputPlane(e);
        plane->SetBullet(e);
        plane->MakeBullet(ren, bullet_texture);
        plane->Show(plane_texture, ren);

        for (int i = 0; i < NUMBER_OF_CHICKEN; i++) {

            Chicken* chicken = chicken_small + i;

            chicken->ChickenMove(SCREEN_WIDTH, SCREEN_HEIGHT);
            chicken->MakeEgg(ren, egg_texture);
            chicken->Show (chicken_texture, ren);

        }

        SDL_RenderPresent(ren);


        frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

    }

    SDL_DestroyTexture (background_texture);
    SDL_DestroyTexture (plane_texture);
    SDL_DestroyTexture (bullet_texture);
    SDL_DestroyTexture (chicken_texture);
    SDL_DestroyTexture (egg_texture);

    delete plane;
    delete [] chicken_small;

}


void Game::EndLoop (SDL_Event &e)
{

    SDL_PollEvent(&e);

    if (e.type == SDL_QUIT) {
        isRunning = false;
    }

    if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_ESCAPE) {
            isRunning = false;
        }
    }

}


void Game::quitSDL()
{

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}

