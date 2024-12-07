#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <functional>
#include <headers/DataStructures.h>

class BaseObj
{
private:
    SDL_Rect DrawDestonation;
    void calculateDrawDest();

protected:
    SDL_Texture *sprite;
    int x;
    int y;
    short width;
    short height;
    bool active;
    // true = drawDest is recalculated each frame if false must use getters/setters to move object
    void inactiveSetPos(int nx, int ny); // use only if active is false otherwise just write to x-y
    // void setDrawLayer(int newLayer); // TODO get this working

public:
    short layer;
    DrawData getDrawData();
    void draw(SDL_Renderer *renderer);
    BaseObj(int x, int y, int w, int h, short DrawLayer = 1,
            SDL_Texture *Sprite = NULL, bool Active = false);
    // add more functions as needed
};