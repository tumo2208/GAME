#include "Game.hpp"


int main (int argc, char* argv[])
{
    Game* g = new Game();
    g->initSDL();

    g->Run();

    g->quitSDL();
    delete g;
    return 0;

}
