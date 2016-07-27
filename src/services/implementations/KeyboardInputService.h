//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_INPUTMANAGER_H
#define SDL_HELLO_WORLD_INPUTMANAGER_H


#include <map>
#include "../InputService.h"

class KeyboardInputService : public InputService {

    bool quit;
    InputState mouseState[3];
    SDL_Point mousePosition;
    std::map<SDL_Keycode, InputState> keyboardState;

    void reset();

public:
    KeyboardInputService();

    virtual void update();

    virtual bool quitPressed();

    virtual bool isKeyUp(SDL_Keycode keyCode);

    virtual bool isKeyDown(SDL_Keycode keyCode);

    virtual bool isMouseButtonUp(MOUSE_BUTTON mouseButton);

    virtual bool isMouseButtonDown(MOUSE_BUTTON mouseButton);

    virtual SDL_Point getMousePosition();
};


#endif //SDL_HELLO_WORLD_INPUTMANAGER_H
