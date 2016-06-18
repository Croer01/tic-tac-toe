//
// Created by Adria on 17/06/2016.
//

#ifndef SDL_HELLO_WORLD_SCENE_H
#define SDL_HELLO_WORLD_SCENE_H


#include <SDL_render.h>
#include "Game.h"

class Game;
class Scene {
protected:

    SDL_Renderer *renderer;

    Game *game;

public:

    Scene(Game *game, SDL_Renderer *renderer);

    virtual void init() = 0;

    virtual void update() = 0;

    virtual void render() = 0;
};


#endif //SDL_HELLO_WORLD_SCENE_H
