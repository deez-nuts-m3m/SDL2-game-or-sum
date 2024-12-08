#pragma once

#include <functional>
#include <sdl/SDL.h>
#include <unordered_map>

struct DrawData
{
    short layer;
    std::function<void(SDL_Renderer *, std::unordered_map<SDL_Keycode, bool> *)> drawFunc;
    bool isUsed = true;
};

struct CompareDrawData
{
    bool operator()(const DrawData *a, const DrawData *b) const
    {
        return a->layer < b->layer;
    }
};
