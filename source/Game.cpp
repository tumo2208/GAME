#include "source/Game.hpp"
#include "source/Plane.hpp"
#include "source/Bullet.hpp"


Plane plane;


Game::Game()
{

}


Game::~Game()
{

}


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


void Game::update()
{

    SDL_Texture* background_texture = Game::loadIMG ("assets/Background_ban_ga.png");
    SDL_Texture* plane_texture = Game::loadIMG ("assets/SpaceShip.png");
    SDL_Texture* bullet_texture = Game::loadIMG ("assets/Bullet_1.png");

    SDL_Event e;
    SDL_RenderCopy(ren, background_texture, NULL, NULL);

    plane.HandleInputPlane(e);
    plane.plane_display(plane_texture, ren);
    plane.MakeBullet(ren, bullet_texture);

}


void Game::EndLoop ()
{

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) isRunning = false;
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
        }
    }

}


void Game::quitSDL()
{

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}
