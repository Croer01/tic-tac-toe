//
// Created by Adria on 12/06/2016.
//

#ifndef SDL_HELLO_WORLD_CELL_H
#define SDL_HELLO_WORLD_CELL_H


#include <SDL_render.h>
#include "../core/Texture.h"

enum CELL_STATE{
    UNCHECKED,
    PLAYER1,
    PLAYER2
};

class Cell : public SDL_Rect {
    Texture* texture;
    SDL_Rect imageClips[2];
    CELL_STATE state;

public:

    Cell(SDL_Rect rect);
    void draw();
    void checkPlayerOne();
    void checkPlayerTwo();
    CELL_STATE getState();
};


#endif //SDL_HELLO_WORLD_CELL_H
