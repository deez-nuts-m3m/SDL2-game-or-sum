#include <headers/BaseObj.h>
#include "BaseObj.h"

BaseObj::BaseObj(int X, int Y, int W, int H, short DrawLayer,
                 SDL_Texture *Sprite)
{
    x = X;
    y = Y;
    width = W;
    height = H;
    layer = DrawLayer;
    sprite = Sprite;

    DrawDestonation = {x, y, width, height};
}

void BaseObj::draw(SDL_Renderer *renderer, std::unordered_map<SDL_Keycode, bool> *keyboard)
{
    if (keyboard->find(SDLK_w) != keyboard->end()) // -> = deref pointer
    {
        y--;
    };
    if (keyboard->find(SDLK_s) != keyboard->end())
    {
        y++;
    };
    if (keyboard->find(SDLK_a) != keyboard->end())
    {
        x--;
    };
    if (keyboard->find(SDLK_d) != keyboard->end())
    {
        x++;
    };
    DrawDestonation = {x, y, width, height};
    SDL_RenderCopy(renderer, sprite, nullptr, &DrawDestonation); // EZ
}

DrawData BaseObj::getDrawData()
{
    DrawData data = {layer, [this](SDL_Renderer *renderer, std::unordered_map<SDL_Keycode, bool> *keyboard)
                     {
                         this->draw(renderer, keyboard);
                     },
                     true};
    return data;
}

void BaseObj::setDrawLayer(short newLayer)
{
    layer = newLayer;
}