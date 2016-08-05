//
// Created by Adria on 05/08/2016.
//

#ifndef TIC_TAC_TOE_BUTTON_H
#define TIC_TAC_TOE_BUTTON_H


#include "Text.h"
#include <functional>
#include <SDL_mouse.h>

class Button : public Text {
bool isInside;
protected:
    std::function<void()> onClickCallback;

    void clickEvent();
public:

    Button();

    void addOnClickHandler(std::function<void()> handler);

    virtual void update();

    virtual void render();
};


#endif //TIC_TAC_TOE_BUTTON_H
