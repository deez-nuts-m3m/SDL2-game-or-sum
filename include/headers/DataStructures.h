#pragma once

#include <functional>
#include <sdl/SDL.h>

struct DrawData
{
    short layer;
    std::function<void(SDL_Renderer *)> drawFunc;
    bool isUsed = true;
};