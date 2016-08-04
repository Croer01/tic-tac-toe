//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_SCENETICTACTOE_H
#define SDL_HELLO_WORLD_SCENETICTACTOE_H


#include "../core/Game.h"
#include "../core/Texture.h"
#include "TableBoard.h"
#include "../core/Scene.h"

class SceneTicTacToe {
    Game* game;
    TableBoard *table;
    SDL_Renderer *renderer;

public:

    SceneTicTacToe(Game *game, SDL_Renderer *renderer) { }

    void init();

    void update();

    void render();


};


#endif //SDL_HELLO_WORLD_SCENETICTACTOE_H
