#pragma once

#include <functional>
#include <sdl/SDL.h>
#include <unordered_map>

struct DrawData
{
    short layer;
    std::function<void(SDL_Renderer *, std::unordered_map<SDL_Keycode, bool> *, MouseData *)> drawFunc;
    bool isUsed = true;
};

struct CompareDrawData
{
    bool operator()(const DrawData *a, const DrawData *b) const
    {
        return a->layer < b->layer;
    }
};

struct MouseData
{
    int x, y;
    bool LMB = false, RMB = false, MMB = false;
    bool LMBPressed = false, RMBPressed = false, MMBPressed = false;
};