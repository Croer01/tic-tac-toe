//
// Created by Adria on 27/07/2016.
//

#include <algorithm>
#include "Element.h"
#include "../../serialization/Serializer.h"
#include "../../core/Game.h"

INIT_METADATA(Element);

Element::Element(std::string name) {
    this->name = name;
}

Component *Element::getComponent(std::string componentName) const{
    auto iterator = std::find_if(components.begin(), components.end(),
                                                                      [componentName](Component *component) {
                                                                          return component->getName() == componentName;
                                                                      });

    return iterator != components.end() ? *iterator : NULL;
}

void Element::addComponent(Component *component) {
    components.push_back(component);
}

void Element::serialize(YAML::Node node) const {
    Object::serialize(node);
    for (Component *component : components) {
        node["components"].push_back(Serializer::Metadata::serialize(component));
    }

}

bool Element::deserialize(YAML::Node node) {
    bool success = Object::deserialize(node);
    YAML::Node componentsSequence = node["components"];
    for (int i = 0; i < componentsSequence.size(); i++) {
        Component *component = (Component *) Serializer::Metadata::deserialize(componentsSequence[i]);
        components.push_back(component);
    }

    return success;
}

void Element::init(Game *game,SDL_Renderer *renderer) {
    this->game = game;
    this->renderer = renderer;

    for (Component *component : components) {
        component->init();
    }
}

void Element::update() {
    for (Component *component : components) {
        component->update();
    }
}

void Element::render() {
    for (Component *component : components) {
        component->render();
    }
}









