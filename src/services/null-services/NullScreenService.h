//
// Created by Adria on 06/08/2016.
//

#ifndef TIC_TAC_TOE_NULLSCREENSERVICE_H
#define TIC_TAC_TOE_NULLSCREENSERVICE_H


#include "../interfaces/ScreenService.h"

class NullScreenService : public ScreenService {
public:

    virtual SDL_Renderer *gerRenderer() const{ return NULL; };

    virtual int getWidth() const{ return 0; };

    virtual int getHeight() const{ return 0; };
};


#endif //TIC_TAC_TOE_NULLSCREENSERVICE_H
