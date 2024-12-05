#define SDL_MAIN_HANDLED
#include <headers/Game.h>

int main(int argc, char *argv[])
{

    Game game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    game.gameLoop();
    return 0;
}