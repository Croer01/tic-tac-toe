//
// Created by Adria on 18/06/2016.
//


#include "UIElement.h"

INIT_METADATA(UIElement);

UIElement::UIElement(SDL_Renderer *renderer, SDL_Rect bounds) : Element() {
    transform = new Transform2D();
    transform->setPosition({x:bounds.x,y:bounds.y});
    transform->setSize({x:bounds.w, y:bounds.h});
    addComponent(transform);
    this->renderer = renderer;
}

void UIElement::serialize(YAML::Node node) const {
    Element::serialize(node);
}

bool UIElement::deserialize(YAML::Node node) {
    bool success = Element::deserialize(node);
    this->transform = (Transform2D*)getComponent("transform2D");

    return success;
}
