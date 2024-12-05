#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

enum class GameState
{
    PLAY,
    EXIT
};

class Game
{
public:
    Game(const char *title, int x, int y, int w, int h, Uint32 flags);
    ~Game();

    void gameLoop();

private:
    void handleEvents();

    SDL_Window *window;
    SDL_Renderer *renderer;

    GameState gameState;
};