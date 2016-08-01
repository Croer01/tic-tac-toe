//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_SCENEMETADATA_H
#define SDL_HELLO_WORLD_SCENEMETADATA_H


#include "../core/Game.h"
#include "../core/Scene.h"

class SceneMetadata : public Scene {

public:

    SceneMetadata(Game *game, SDL_Renderer *renderer) : Scene(game, renderer) { }

    void init();

    void update();

    void render();

};


#endif //SDL_HELLO_WORLD_SCENEMETADATA_H
