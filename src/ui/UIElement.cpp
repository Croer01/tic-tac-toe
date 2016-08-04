//
// Created by Adria on 18/06/2016.
//


#include "UIElement.h"
#include "../services/GameServices.h"
INIT_METADATA(UIElement);

UIElement::UIElement(SDL_Renderer *renderer, SDL_Rect bounds) : Element() {
    this->bounds = bounds;
    this->renderer = renderer;
}

void UIElement::update() {
    Element::update();
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


void UIElement::serialize(YAML::Node node) const {
    Element::serialize(node);
    node["bounds"]["x"] = bounds.x;
    node["bounds"]["y"] = bounds.y;
    node["bounds"]["w"] = bounds.w;
    node["bounds"]["h"] = bounds.h;
}

bool UIElement::deserialize(YAML::Node node) {
    bool success = Element::deserialize(node);

    bounds = {
            x :node["bounds"]["x"].as<int>(),
            y :node["bounds"]["y"].as<int>(),
            w :node["bounds"]["w"].as<int>(),
            h :node["bounds"]["h"].as<int>()
    };

    return success;
}
