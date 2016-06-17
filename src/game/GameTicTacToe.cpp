//
// Created by Adria on 11/06/2016.
//

#include <SDL.h>
#include "GameTicTacToe.h"

GameTicTacToe::GameTicTacToe() : Game() { }

bool GameTicTacToe::init(int screenWith, int screenHeight) {
    bool success = Game::init(screenWith, screenHeight);

    table = new TableBoard(screenWith, screenHeight, renderer);

    return success;
}

void GameTicTacToe::update() {
    Game::update();
    table->update();
    if(table->checkGameEnds() != 0)
        running = false;

}

void GameTicTacToe::draw() {
    table->draw();
}













