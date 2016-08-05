//
// Created by Adria on 18/06/2016.
//


#include "UIElement.h"
#include "../services/GameServices.h"

INIT_METADATA(UIElement);

UIElement::UIElement(SDL_Renderer *renderer, SDL_Rect bounds) : Element() {
    transform = new Transform2D();
    transform->setPosition({x:bounds.x,y:bounds.y});
    transform->setSize({x:bounds.w, y:bounds.h});
    addComponent(transform);
    this->renderer = renderer;
}

void UIElement::update() {
    Element::update();
    if (GameServices::getInput()->isMouseButtonDown(MOUSE_BUTTON::LEFT)) {
        SDL_Point mousePos = GameServices::getInput()->getMousePosition();
        SDL_Rect rect = transform->getRect();
        if (SDL_PointInRect(&mousePos, &rect)) {
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


void UIElement::serialize(YAML::Node node) const {
    Element::serialize(node);
}

bool UIElement::deserialize(YAML::Node node) {
    bool success = Element::deserialize(node);
    this->transform = (Transform2D*)getComponent("transform2D");

    return success;
}
