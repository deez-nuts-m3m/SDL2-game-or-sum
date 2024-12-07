#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <functional>
#include <headers/DataStructures.h>

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
    void draw(SDL_Renderer *renderer);
    BaseObj(int x, int y, int w, int h, short DrawLayer = 1,
            SDL_Texture *Sprite = NULL);
    // add more functions as needed
};