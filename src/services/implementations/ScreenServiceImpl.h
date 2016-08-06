//
// Created by Adria on 06/08/2016.
//

#ifndef TIC_TAC_TOE_SCREENSERVICEIMPL_H
#define TIC_TAC_TOE_SCREENSERVICEIMPL_H


#include "../interfaces/ScreenService.h"

class ScreenServiceImpl : public ScreenService {
    SDL_Renderer *renderer;
    int width;
    int height;
public:
    ScreenServiceImpl(SDL_Renderer *renderer);

    virtual SDL_Renderer *gerRenderer() const;

    virtual int getWidth() const;

    virtual int getHeight() const;
};


#endif //TIC_TAC_TOE_SCREENSERVICEIMPL_H
