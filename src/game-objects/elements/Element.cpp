//
// Created by Adria on 27/07/2016.
//

#include <algorithm>
#include "Element.h"
#include "../../serialization/Serializer.h"
#include "../components/Transform2D.h"

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
        node["components"].push_back(Metadata::serialize(component));
    }

}

bool Element::deserialize(YAML::Node node) {
    bool success = Object::deserialize(node);
    YAML::Node componentsSequence = node["components"];
    for (int i = 0; i < componentsSequence.size(); i++) {
        Component *component = (Component *) Metadata::deserialize(componentsSequence[i]);
        component->setElement(this);
        components.push_back(component);
    }

    transform = (Transform2D*)getComponent("transform2D");

    return success;
}

void Element::init() {
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

Transform2D *Element::getTransform() const {
    return transform;
}
