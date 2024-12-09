#pragma once

#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <functional>
#include <headers/DataStructures.h>
#include <unordered_map>

class BaseObj
{
private:
    SDL_Rect DrawDestonation;

protected:
    SDL_Texture *sprite;
    int x;
    int y;
    short width;
    short height;
    void setDrawLayer(short newLayer);

public:
    short layer;
    DrawData getDrawData();
    void draw(SDL_Renderer *renderer, std::unordered_map<SDL_Keycode, bool> *keyboard, MouseData *mouseInfo);
    BaseObj(int x, int y, int w, int h, short DrawLayer = 1,
            SDL_Texture *Sprite = NULL);
    void draw(SDL_Renderer *renderer);
};