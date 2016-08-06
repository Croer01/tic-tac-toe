//
// Created by Adria on 11/06/2016.
//

#include <SDL_events.h>
#include "KeyboardInputServiceImpl.h"

KeyboardInputServiceImpl::KeyboardInputServiceImpl() : InputService(){
    quit = false;
    mousePosition.x = -1;
    mousePosition.y = -1;
}

//public accessors

void KeyboardInputServiceImpl::update() {
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

bool KeyboardInputServiceImpl::quitPressed() {
    return quit;
}

bool KeyboardInputServiceImpl::isKeyUp(SDL_Keycode keyCode) {
    return keyboardState[keyCode] == UP;
}

bool KeyboardInputServiceImpl::isKeyDown(SDL_Keycode keyCode) {
    return keyboardState[keyCode] == DOWN;
}

bool KeyboardInputServiceImpl::isMouseButtonUp(MOUSE_BUTTON mouseButton) {
    return mouseState[mouseButton] == UP;
}

bool KeyboardInputServiceImpl::isMouseButtonDown(MOUSE_BUTTON mouseButton) {
    return mouseState[mouseButton] == DOWN;
}

SDL_Point KeyboardInputServiceImpl::getMousePosition() {
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    return mousePosition;
}

//private implementations

void KeyboardInputServiceImpl::reset() {
    for (std::pair<const int, KeyboardInputServiceImpl::InputState> &iterator : keyboardState) {
        iterator.second = NONE;
    }
    for (int i = 0; i < MOUSE_BUTTON::MAX_BUTTON; ++i) {
        mouseState[i] = NONE;
    }
}
