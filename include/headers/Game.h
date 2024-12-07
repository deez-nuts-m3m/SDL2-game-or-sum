#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <vector>
#include <stack>
#include <headers/DataStructures.h>
#include <algorithm>

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
    void render();

    int addToRenderList(DrawData data);

private:
    void handleEvents();
    void sortDrawList();
    std::vector<DrawData> drawList; // i have no idea what im doing
    std::stack<int> emptyList;
    SDL_Window *window;
    SDL_Renderer *renderer;

    GameState gameState;
};