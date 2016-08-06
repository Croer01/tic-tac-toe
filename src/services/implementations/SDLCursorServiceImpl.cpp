//
// Created by Adria on 05/08/2016.
//

#include "SDLCursorServiceImpl.h"

SDLCursorServiceImpl::~SDLCursorServiceImpl() {
    for (auto cursor: cursors) {
        SDL_FreeCursor(cursor.second);
    }
    cursors.clear();
}

void SDLCursorServiceImpl::setCursor(SDL_SystemCursor cursor) {
    SDL_Cursor *pointer = NULL;
    auto iterator = cursors.find(cursor);
    if (iterator != cursors.end()) {
        pointer = iterator->second;
    }
    else {
        pointer = SDL_CreateSystemCursor(cursor);
        cursors[cursor] = pointer;
    }

    SDL_SetCursor(pointer);
}
