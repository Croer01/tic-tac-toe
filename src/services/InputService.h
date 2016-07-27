//
// Created by Adria on 27/07/2016.
//

#ifndef SDL_HELLO_WORLD_INPUTSERVICE_H
#define SDL_HELLO_WORLD_INPUTSERVICE_H


#include <SDL_rect.h>
#include <SDL_keycode.h>

enum MOUSE_BUTTON {
    LEFT,
    RIGHT,
    MIDDLE,
    MAX_BUTTON
};


class InputService {
protected:
    enum InputState {
        NONE, UP, DOWN
    };
public:
    virtual ~InputService() { }

    virtual void update() = 0;

    virtual bool quitPressed() = 0;

    virtual bool isKeyUp(SDL_Keycode keyCode) = 0;

    virtual bool isKeyDown(SDL_Keycode keyCode) = 0;

    virtual bool isMouseButtonUp(MOUSE_BUTTON mouseButton) = 0;

    virtual bool isMouseButtonDown(MOUSE_BUTTON mouseButton) = 0;

    virtual SDL_Point getMousePosition() = 0;
};


#endif //SDL_HELLO_WORLD_INPUTSERVICE_H
