#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
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

    std::unordered_map<SDL_Keycode, bool> keyMap;
    MouseData mouseInfo;

    void addToRenderList(DrawData data);

private:
    void render();
    void handleEvents();
    std::multiset<DrawData *, CompareDrawData> drawList; // this is supposed to be fast
    std::unordered_set<int> emptyList;
    SDL_Window *window;
    SDL_Renderer *renderer;

    int frameDelay = 1000 / 60; // 60 FPS
    int frameStart, frameTime, lastFrameTime;

    GameState gameState;
};