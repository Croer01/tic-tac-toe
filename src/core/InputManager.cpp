//
// Created by Adria on 11/06/2016.
//

#include <SDL_events.h>
#include "InputManager.h"

InputManager *InputManager::instance = NULL;

InputManager::InputManager() {
    quit = false;
    mousePosition.x = -1;
    mousePosition.y = -1;
}

//public accessors

void InputManager::update() {
    getInstance()->instance_Update();
}

bool InputManager::quitPressed() {
    return getInstance()->instance_QuitPressed();
}

bool InputManager::isKeyUp(SDL_Keycode keyCode) {
    return getInstance()->instance_IsKeyUp(keyCode);
}

bool InputManager::isKeyDown(int keyCode) {
    return getInstance()->instance_IsKeyDown(keyCode);
}

bool InputManager::isMouseButtonUp(MOUSE_BUTTON mouseButton) {
    return getInstance()->instance_IsMouseButtonUp(mouseButton);
}

bool InputManager::isMouseButtonDown(MOUSE_BUTTON mouseButton) {
    return getInstance()->instance_IsMouseButtonDown(mouseButton);
}

SDL_Point InputManager::getMousePosition() {
    return getInstance()->instance_GetMousePosition();
}

//private implementations

void InputManager::reset() {
    for (std::pair<const int, InputManager::InputState> &iterator : keyboardState) {
        iterator.second = NONE;
    }
    for (int i = 0; i < MOUSE_BUTTON::MAXBUTTON; ++i) {
        mouseState[i] = NONE;
    }
}

void InputManager::instance_Update() {
    reset();

    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {

        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                keyboardState[event.key.keysym.sym] = DOWN;
                break;
            case SDL_KEYUP:
                keyboardState[event.key.keysym.sym] = UP;
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                        mouseState[MOUSE_BUTTON::LEFT] = DOWN;
                        break;
                    case SDL_BUTTON_RIGHT:
                        mouseState[MOUSE_BUTTON::RIGHT] = DOWN;
                        break;
                    case SDL_BUTTON_MIDDLE:
                        mouseState[MOUSE_BUTTON::MIDDLE] = DOWN;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                        mouseState[MOUSE_BUTTON::LEFT] = UP;
                        break;
                    case SDL_BUTTON_RIGHT:
                        mouseState[MOUSE_BUTTON::RIGHT] = UP;
                        break;
                    case SDL_BUTTON_MIDDLE:
                        mouseState[MOUSE_BUTTON::MIDDLE] = UP;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

bool InputManager::instance_QuitPressed() {
    return quit;
}

bool InputManager::instance_IsKeyUp(SDL_Keycode keyCode) {
    return keyboardState[keyCode] == UP;
}

bool InputManager::instance_IsKeyDown(int keyCode) {
    return keyboardState[keyCode] == DOWN;
}

bool InputManager::instance_IsMouseButtonUp(MOUSE_BUTTON mouseButton) {
    return mouseState[mouseButton] == UP;
}

bool InputManager::instance_IsMouseButtonDown(MOUSE_BUTTON mouseButton) {
    return mouseState[mouseButton] == DOWN;
}

SDL_Point InputManager::instance_GetMousePosition() {
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    return mousePosition;
}

InputManager *InputManager::getInstance() {
    if (instance == NULL)
        instance = new InputManager();
    return instance;
}




















