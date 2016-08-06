//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_TABLEBOARD_H
#define SDL_HELLO_WORLD_TABLEBOARD_H


#include <SDL_render.h>
#include "Cell.h"
#include "../game-objects/components/Component.h"

class TableBoard : public Component {
CREATE_METADATA(TableBoard);
    static const int ROW_SIZE = 3;

    Cell *cells[ROW_SIZE * ROW_SIZE];
    int player;

    void initCells(int screenWith, int screenHeight);

    void togglePlayers();

    int checkGameEnds();

public:
    TableBoard() : Component() { };

    virtual void init();

    virtual void update();

    virtual void render();

};


#endif //SDL_HELLO_WORLD_TABLEBOARD_H
