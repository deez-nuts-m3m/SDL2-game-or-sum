#include <headers/Player.h>
#include <iostream>

Player::Player(int x, int y, int w, int h, short DrawLayer, SDL_Texture *Sprite) : BaseObj(x, y, w, h, DrawLayer, Sprite) {}

void Player::draw(SDL_Renderer *renderer, std::unordered_map<SDL_Keycode, bool> *keyboard, MouseData *mouseInfo)
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

    SDL_RenderCopy(renderer, sprite, nullptr, &DrawDestonation);
}

DrawData Player::getDrawData()
{
    DrawData data = {layer, [this](SDL_Renderer *renderer, std::unordered_map<SDL_Keycode, bool> *keyboard, MouseData *mouseInfo)
                     {
                         this->draw(renderer, keyboard, mouseInfo);
                     },
                     true};
    return data;
}