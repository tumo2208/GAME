#pragma once


#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_audio.h>
using namespace std;


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 769;
const string SCREEN_TITLE = "Ban Ga";


class Game {

public:

    Game();
    ~Game();

    void initSDL();
    SDL_Texture* loadIMG (const string path);
    void Clear() {SDL_RenderClear(ren);}
    void update();
    void Draw() {SDL_RenderPresent(ren);}
    void EndLoop();
    void quitSDL();

    bool Running() {return isRunning;}


private:

    SDL_Window* win;
    SDL_Renderer* ren;
    bool isRunning;

};
