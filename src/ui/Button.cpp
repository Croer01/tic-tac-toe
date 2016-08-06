//
// Created by Adria on 05/08/2016.
//

#include "Button.h"
#include "../services/GameServices.h"
#include "../game-objects/components/Transform2D.h"

INIT_METADATA(Button);

Button::Button() : Text() {
    isInside = false;
}

void Button::clickEvent() {
    if (onClickCallback) {
        onClickCallback();
    }
}

void Button::addOnClickHandler(std::function<void()> handler) {
    onClickCallback = handler;
}

void Button::update() {
    Text::update();
    SDL_Point mousePos = GameServices::getInput()->getMousePosition();
    SDL_Rect rect = element->getTransform()->getRect();

    if (SDL_PointInRect(&mousePos, &rect)) {
        if (!isInside) {
            GameServices::getCursor()->setCursor(SDL_SYSTEM_CURSOR_HAND);
            isInside = true;
        }
        if (GameServices::getInput()->isMouseButtonDown(MOUSE_BUTTON::LEFT)) {
            clickEvent();
        }
    }
    else {
        if (isInside) {
            GameServices::getCursor()->setCursor(SDL_SYSTEM_CURSOR_ARROW);
            isInside = false;
        }
    }

}


void Button::render() {
    SDL_Renderer *renderer = GameServices::getScreen()->gerRenderer();
    const SDL_Rect &size = element->getTransform()->getRect();
    if (isInside) {
        SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
    }
    SDL_RenderFillRect(renderer, &size);
    Text::render();
}
