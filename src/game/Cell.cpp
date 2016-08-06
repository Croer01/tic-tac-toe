//
// Created by Adria on 12/06/2016.
//

#include "Cell.h"
#include "../services/GameServices.h"

Cell::Cell(SDL_Rect rect) {
    //textures
    texture = GameServices::getImage()->getTextureByFileName("assets/images/tic-tac-toe.png");
    imageClips[0] = {0, 0, texture->getWidth() / 2, texture->getHeight()};
    imageClips[1] = {texture->getWidth() / 2, 0, texture->getWidth() / 2, texture->getHeight()};

    //rect
    x = rect.x;
    y = rect.y;
    w = rect.w;
    h = rect.h;

    state = UNCHECKED;
}

void Cell::draw() {
    SDL_SetRenderDrawColor(GameServices::getScreen()->gerRenderer(), 0x00, 0x00, 0x00, 0xFF);

    switch (state) {
        case PLAYER1:
            texture->draw(*this, imageClips[0]);
            break;
        case PLAYER2:
            texture->draw(*this, imageClips[1]);
            break;
    }

    SDL_RenderDrawRect(GameServices::getScreen()->gerRenderer(), this);
}

void Cell::checkPlayerOne() {
    state = PLAYER1;
}

void Cell::checkPlayerTwo() {
    state = PLAYER2;

}

CELL_STATE Cell::getState() {
    return state;
}









