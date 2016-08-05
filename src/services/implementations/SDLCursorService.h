//
// Created by Adria on 05/08/2016.
//

#ifndef TIC_TAC_TOE_SDLCURSORSERVICE_H
#define TIC_TAC_TOE_SDLCURSORSERVICE_H


#include <SDL_mouse.h>
#include <map>
#include "../CursorService.h"

class SDLCursorService :public CursorService{
    std::map<SDL_SystemCursor, SDL_Cursor *> cursors;
public:
    virtual ~SDLCursorService();

    virtual void setCursor(SDL_SystemCursor cursor);
};


#endif //TIC_TAC_TOE_SDLCURSORSERVICE_H
