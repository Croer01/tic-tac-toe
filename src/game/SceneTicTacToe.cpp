//
// Created by Adria on 11/06/2016.
//

#include <SDL.h>
#include "SceneTicTacToe.h"

void SceneTicTacToe::init() {
    int screenWith = 0;
    int screenHeight = 0;
    SDL_GetRendererOutputSize(renderer,&screenWith,&screenHeight);
    table = new TableBoard(screenWith, screenHeight, renderer);

}

void SceneTicTacToe::update() {
    table->update();
    if(table->checkGameEnds() != 0)
        game->exit();

}

void SceneTicTacToe::render() {
    table->draw();
}















