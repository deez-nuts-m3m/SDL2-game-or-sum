#include <headers/Game.h>
#include <iostream>

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
        frameStart = SDL_GetTicks();

        handleEvents();
        render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

        std::cout << "FPS: " << 1000 / (frameTime > 0 ? frameTime : 1) << std::endl;
    };
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        gameState = GameState::EXIT;
        break;

    case SDL_KEYDOWN:
        if (keyMap.find(event.key.keysym.sym) != keyMap.end()) // if key is in map
        {
            keyMap[event.key.keysym.sym] = false;
        }
        else
        {
            keyMap[event.key.keysym.sym] = true;
        }
        break;
    case SDL_KEYUP:
        keyMap.erase(event.key.keysym.sym);
        break;
    default:
        break;
    }
};

void Game::render()
{
    SDL_RenderClear(renderer);

    for (auto it = drawList.begin(); it != drawList.end();) // ngl chat gpt did this one
    {
        if ((*it)->isUsed)
        {
            (*it)->drawFunc(renderer, &keyMap);
            ++it;
        }
        else
        {
            it = drawList.erase(it);
        }
    }

    SDL_RenderPresent(renderer);
};

SDL_Texture *Game::loadTexture(const char *path)
{
    SDL_Texture *texture = NULL;

    texture = IMG_LoadTexture(renderer, path);

    return texture;
}

void Game::addToRenderList(DrawData data)
{
    drawList.insert(&data);
}
