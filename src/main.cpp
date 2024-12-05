#define SDL_MAIN_HANDLED
#include <headers/Game.h>

int main(int argc, char *argv[])
{
    Game game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    SDL_Texture *texture = game.loadTexture("C:\\Users\\rtp43\\OneDrive\\Desktop\\SDL2 game or sum\\res\\img.png");

    game.render(texture);

    game.gameLoop();
    return 0;
}