#include <headers/BaseObj.h>

BaseObj::BaseObj(int X, int Y, int W, int H, short DrawLayer,
                 SDL_Texture *Sprite, bool Active)
{
    x = X;
    y = Y;
    width = W;
    height = H;
    layer = DrawLayer;
    sprite = Sprite;
    active = Active;

    calculateDrawDest();
}

void BaseObj::calculateDrawDest() // did not know SDL_Rect was x, y, w, h i thought it was x, y, x2, y2 so this function is useless
{
    DrawDestonation = {x, y, width, height}; // ezz
}

void BaseObj::inactiveSetPos(int nx, int ny)
{
    x = nx;
    y = ny;
    calculateDrawDest();
}

void BaseObj::draw(SDL_Renderer *renderer)
{
    calculateDrawDest();
    SDL_RenderCopy(renderer, sprite, nullptr, &DrawDestonation); // EZ
}

DrawData BaseObj::getDrawData()
{
    DrawData data = {layer, std::bind(&BaseObj::draw, this, std::placeholders::_1), true};
    return data;
}