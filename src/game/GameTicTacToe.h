//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_GAMETICTACTOE_H
#define SDL_HELLO_WORLD_GAMETICTACTOE_H


#include "../core/Game.h"
#include "../core/Texture.h"
#include "TableBoard.h"

class GameTicTacToe : public Game {
public:
    GameTicTacToe();

    bool init(int screenWith, int screenHeight);

    void update();

    void draw();

private:
    TableBoard* table;
};


#endif //SDL_HELLO_WORLD_GAMETICTACTOE_H
