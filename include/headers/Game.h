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
    SDL_Texture *loadTexture(const char *path);
    void render(SDL_Texture *texture);

private:
    void handleEvents();

    void clear();
    void display();
    SDL_Window *window;
    SDL_Renderer *renderer;

    GameState gameState;
};