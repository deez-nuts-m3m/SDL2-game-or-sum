#include <headers/BaseObj.h>

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

void BaseObj::draw(SDL_Renderer *renderer)
{
    SDL_RenderCopy(renderer, sprite, nullptr, &DrawDestonation); // EZ
}

DrawData BaseObj::getDrawData()
{
    DrawData data = {layer, std::bind(&BaseObj::draw, this, std::placeholders::_1), true};
    return data;
}

void BaseObj::setDrawLayer(short newLayer)
{
    layer = newLayer;
}