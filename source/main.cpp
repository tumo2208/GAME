#include "source/Game.hpp"

Game* g = nullptr;


int main (int argc, char* argv[])
{
    g = new Game();
    g->initSDL();

    const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

    while (g->Running())
    {
        frameStart = SDL_GetTicks();

        g->EndLoop();
        g->Clear();
        g->update();
        g->Draw();

        frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
    }

    g->quitSDL();
    return 0;

}
