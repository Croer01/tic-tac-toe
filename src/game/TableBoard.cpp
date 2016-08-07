//
// Created by Adria on 11/06/2016.
//

#include "TableBoard.h"
#include "../services/GameServices.h"
#include "../elements/WorldElement.h"

INIT_METADATA(TableBoard);


void TableBoard::initCells(int screenWith, int screenHeight) {

    int cellWidth = screenWith / ROW_SIZE;
    int cellHeight = screenHeight / ROW_SIZE;

    for (int i = 0; i < ROW_SIZE; ++i) {
        for (int j = 0; j < ROW_SIZE; ++j) {
            SDL_Rect rect;
            rect.x = j * cellWidth;
            rect.y = i * cellHeight;
            rect.w = cellWidth;
            rect.h = cellHeight;
            cells[i * ROW_SIZE + j] = new Cell(rect);
        }
    }
}

void TableBoard::togglePlayers() {
    player ^= 1;
}

int TableBoard::checkGameEnds() {
    int player = 0;
    Cell *cell = NULL;

    //first diagonal
    if (cells[0]->getState() == cells[4]->getState() && cells[4]->getState() == cells[8]->getState() ||
        //second diagonal
        cells[2]->getState() == cells[4]->getState() && cells[4]->getState() == cells[6]->getState()) {
        cell = cells[4];
    }

    for (int i = 0; cell == NULL && i < ROW_SIZE; ++i) {
        int row = i * ROW_SIZE;

        //vertical
        if (cells[i]->getState() == cells[i + ROW_SIZE]->getState() &&
            cells[i + ROW_SIZE]->getState() == cells[i + ROW_SIZE * 2]->getState()) {
            cell = cells[i];
        }
        //horizontal
        if (cells[row]->getState() == cells[row + 1]->getState() &&
            cells[row + 1]->getState() == cells[row + 2]->getState()) {
            cell = cells[row];
        }

    }

    if (cell != NULL) {
        if (cell->getState() == PLAYER1) {
            player = 1;
        } else if (cell->getState() == PLAYER2) {
            player = 2;
        }
    }

    return player;
}


void TableBoard::init() {
    Component::init();
    player = 0;
    Transform2D* transform= ((WorldElement*)element)->getTransform();
    initCells(transform->getSize().x, transform->getSize().y);
}

void TableBoard::update() {
    Component::update();
    if (GameServices::getInput()->isMouseButtonDown(LEFT)) {
        SDL_Point mousePos = GameServices::getInput()->getMousePosition();
        for (int i = 0; i < ROW_SIZE * ROW_SIZE; i++) {
            Cell *cell = cells[i];
            if (cell->getState() == UNCHECKED && SDL_PointInRect(&mousePos, cell)) {
                if (player == 0) {
                    cell->checkPlayerOne();
                } else if (player == 1) {
                    cell->checkPlayerTwo();
                }
                togglePlayers();
                break;
            }
        }
    }

    if(checkGameEnds() != 0)
        GameServices::getScenes()->changeScene("main Menu");
}

void TableBoard::render() {
    Component::render();
    for (int i = 0; i < ROW_SIZE * ROW_SIZE; i++) {
        cells[i]->draw();
    }
}
