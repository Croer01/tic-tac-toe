//
// Created by Adria on 18/06/2016.
//


#include "UIElement.h"
#include "../services/GameServices.h"

UIElement::UIElement(SDL_Renderer *renderer, SDL_Rect bounds) {
    this->bounds = bounds;
    this->renderer = renderer;
}

void UIElement::update() {
    if (GameServices::getInput()->isMouseButtonDown(MOUSE_BUTTON::LEFT)) {
        SDL_Point mousePos = GameServices::getInput()->getMousePosition();
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







