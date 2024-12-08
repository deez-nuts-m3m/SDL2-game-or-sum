#define SDL_MAIN_HANDLED // if this is not here the compiler will whip my ass
#include <headers/Game.h>
#include <headers/BaseObj.h>

int main(int argc, char *argv[])
{
    Game game("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);

    SDL_Texture *image = game.loadTexture("res/img.png");
    SDL_Texture *sunset = game.loadTexture("res/sunset.jpg"); // prob shouldent show full path but im lazy
    SDL_Texture *randomImage = game.loadTexture("res/bean.png");

    BaseObj testObj = BaseObj(300, 100, 150, 200, 1, image);
    BaseObj testObj2 = BaseObj(0, 0, 100, 100, 3, sunset);
    BaseObj testObj3 = BaseObj(50, 75, 300, 300, 2, randomImage);

    game.addToRenderList(testObj.getDrawData());
    game.addToRenderList(testObj2.getDrawData());
    game.addToRenderList(testObj3.getDrawData());

    game.gameLoop();
    return 0;
}