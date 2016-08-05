//
// Created by Adria on 05/08/2016.
//

#ifndef TIC_TAC_TOE_CURSORSERVICE_H
#define TIC_TAC_TOE_CURSORSERVICE_H

#include <SDL_mouse.h>

class CursorService {
public:
    virtual ~CursorService(){};

    virtual void setCursor(SDL_SystemCursor cursor) = 0;
};

#endif //TIC_TAC_TOE_CURSORSERVICE_H
