//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_TABLEBOARD_H
#define SDL_HELLO_WORLD_TABLEBOARD_H


#include <SDL_render.h>
#include "Cell.h"

class TableBoard {
    static const int ROW_SIZE = 3;

    int width;
    int height;
    SDL_Renderer *renderer;
    Cell *cells[ROW_SIZE * ROW_SIZE];
    int player;

    void initCells(int screenWith, int screenHeight);

public:
    TableBoard(int width, int height,SDL_Renderer *renderer);
    ~TableBoard();

    void draw();
    void update();

    void togglePlayers();
    int checkGameEnds();
};


#endif //SDL_HELLO_WORLD_TABLEBOARD_H
