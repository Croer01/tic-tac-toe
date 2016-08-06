//
// Created by Adria on 06/08/2016.
//

#ifndef TIC_TAC_TOE_SCREENSERVICE_H
#define TIC_TAC_TOE_SCREENSERVICE_H


#include <SDL_render.h>

class ScreenService {
public:
    virtual ~ScreenService() { };

    virtual SDL_Renderer *gerRenderer() const = 0;

    virtual int getWidth() const = 0;

    virtual int getHeight() const = 0;
};


#endif //TIC_TAC_TOE_SCREENSERVICE_H
