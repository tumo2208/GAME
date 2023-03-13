#pragma once


#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using namespace std;


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 769;
const int SCREEN_MOVE_SPEED = 1;
const string SCREEN_TITLE = "Ban Ga";


class Game {

public:

    Game() {}
    ~Game() {}

    SDL_Texture* loadIMG(const string path);

    void initSDL();

    void Run();
    void EndLoop(SDL_Event &e);
    void quitSDL();

    bool Running() {return isRunning;}


private:

    SDL_Window* win;
    SDL_Renderer* ren;
    bool isRunning;

};
