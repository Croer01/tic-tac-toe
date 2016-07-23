//
// Created by Adria on 18/06/2016.
//


#include "UIElement.h"
#include "../core/InputManager.h"

UIElement::UIElement(SDL_Renderer *renderer, SDL_Rect bounds) {
    this->bounds = bounds;
    this->renderer = renderer;
}

void UIElement::update() {
    if (InputManager::isMouseButtonDown(MOUSE_BUTTON::LEFT)) {
        SDL_Point mousePos = InputManager::getMousePosition();
        if (SDL_PointInRect(&mousePos, &bounds)) {
            clickEvent();
        }
    }
}

void UIElement::clickEvent() {
    if (onClickCallback) {
        onClickCallback();
    }
}

void UIElement::addOnClickHandler(std::function<void()> handler) {
    onClickCallback = handler;
}







