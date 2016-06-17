//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_GAME_H
#define SDL_HELLO_WORLD_GAME_H


#include <SDL_video.h>
#include <SDL_render.h>

class Game {
    bool initSDLImageModule();

    bool createRenderer();

    bool createWindow(int screenWidth, int screenHeight);

    bool initSDL();

protected:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;

    virtual void initManagers();

public:
    Game();

    virtual ~Game();

    virtual bool init(int screenWidth, int screenHeight);

    virtual void update();

    virtual void draw() = 0;

    void render();

    bool isRunning();
};


#endif //SDL_HELLO_WORLD_GAME_H
