//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_NULLINPUTSERVICE_H
#define TIC_TAC_TOE_NULLINPUTSERVICE_H


#include <SDL_rect.h>
#include "../InputService.h"

class NullInputService : public InputService{
public:
    virtual void update(){};

    virtual bool quitPressed(){ return false;}

    virtual bool isKeyUp(SDL_Keycode keyCode){return false;}

    virtual bool isKeyDown(SDL_Keycode keyCode){return false;}

    virtual bool isMouseButtonUp(MOUSE_BUTTON mouseButton){return false;}

    virtual bool isMouseButtonDown(MOUSE_BUTTON mouseButton){return false;}

    virtual SDL_Point getMousePosition(){return {x:0,y:0};}
};


#endif //TIC_TAC_TOE_NULLINPUTSERVICE_H
