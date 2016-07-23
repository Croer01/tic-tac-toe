//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_INPUTMANAGER_H
#define SDL_HELLO_WORLD_INPUTMANAGER_H


#include <map>
#include <SDL.h>


enum MOUSE_BUTTON {
    LEFT,
    RIGHT,
    MIDDLE,

    MAXBUTTON
};

class InputManager {

    enum InputState {
        NONE, UP, DOWN
    };

    bool quit;
    InputState mouseState[3];
    SDL_Point mousePosition;
    std::map<SDL_Keycode, InputState> keyboardState;

    void reset();

    //singleton
    static InputManager *instance;
    static InputManager *getInstance();

    InputManager();

    //internal implementations
    void instance_Update();

    bool instance_QuitPressed();

    bool instance_IsKeyUp(SDL_Keycode keyCode);

    bool instance_IsKeyDown(SDL_Keycode keyCode);

    bool instance_IsMouseButtonUp(MOUSE_BUTTON mouseButton);

    bool instance_IsMouseButtonDown(MOUSE_BUTTON mouseButton);

    SDL_Point instance_GetMousePosition();

public:

    static void update();

    static bool quitPressed();

    static bool isKeyUp(SDL_Keycode keyCode);

    static bool isKeyDown(SDL_Keycode keyCode);

    static bool isMouseButtonUp(MOUSE_BUTTON mouseButton);

    static bool isMouseButtonDown(MOUSE_BUTTON mouseButton);

    static SDL_Point getMousePosition();
};


#endif //SDL_HELLO_WORLD_INPUTMANAGER_H
