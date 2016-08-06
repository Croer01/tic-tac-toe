//
// Created by Adria on 05/08/2016.
//

#ifndef TIC_TAC_TOE_NULLCURSORSERVICE_H
#define TIC_TAC_TOE_NULLCURSORSERVICE_H

#include "../interfaces/CursorService.h"

class NullCursorService: public CursorService {
public:
    virtual ~NullCursorService(){};

    virtual void setCursor(SDL_SystemCursor cursor) {};
};

#endif //TIC_TAC_TOE_NULLCURSORSERVICE_H
