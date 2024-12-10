#include <headers/BaseObj.h>

class Player : public BaseObj
{
public:
    Player(int x, int y, int w, int h, short DrawLayer = 1,
           SDL_Texture *Sprite = NULL);

    DrawData getDrawData();
    void draw(SDL_Renderer *renderer, std::unordered_map<SDL_Keycode, bool> *keyboard, MouseData *mouseInfo);
};