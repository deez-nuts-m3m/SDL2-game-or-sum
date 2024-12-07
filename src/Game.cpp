#include <headers/Game.h>

Game::Game(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    gameState = GameState::PLAY;

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, x, y, w, h, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
};

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
};

void Game::gameLoop()
{
    while (gameState != GameState::EXIT)
    {
        handleEvents();
    };
};

void Game::handleEvents() // TODO add player input
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        gameState = GameState::EXIT;
        break;

    default:
        break;
    }
};

void Game::render() // TODO make it so textures are renderd from BaseObj
{
    SDL_RenderClear(renderer);

    for (DrawData drawInfo : drawList)
    {
        drawInfo.drawFunc(renderer);
    }

    SDL_RenderPresent(renderer);
};

SDL_Texture *Game::loadTexture(const char *path)
{
    SDL_Texture *texture = NULL;

    texture = IMG_LoadTexture(renderer, path);

    return texture;
}

int Game::addToRenderList(DrawData data)
{
    if (!emptyList.empty())
    {
        int i = emptyList.top();
        drawList[i] = data;
        emptyList.pop();
        sortDrawList(); // TODO make this more efficient
        return i;
    }
    else
    {
        drawList.push_back(data);
        sortDrawList(); // TODO make this more efficient
        return drawList.size() - 1;
    };
}

void Game::sortDrawList()
{
    std::sort(drawList.begin(), drawList.end(), [](const DrawData &a, const DrawData &b)
              {
                  return a.layer < b.layer; // Compare layers
              });
}