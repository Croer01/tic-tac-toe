//
// Created by Adria on 27/07/2016.
//

#include <algorithm>
#include "Element.h"
#include "../../serialization/Serializer.h"

INIT_INSTANTIATOR(Element);

Element::Element(std::string name) {
    this->name = name;
}

Component *Element::getComponent(std::string name) {
    const std::vector<Component *>::iterator &iterator = std::find_if(components.begin(), components.end(),
                                                                      [name](Component *component) {
                                                                          return component->getName() == name;
                                                                      });

    return iterator != components.end() ? *iterator : NULL;
}

void Element::addComponent(Component *component) {
    components.push_back(component);
}

void Element::serialize(YAML::Node node) const {
    Object::serialize(node);
    for (Component *component : components) {
        node["components"].push_back(*component);
    }

}

bool Element::deserialize(YAML::Node node) {
    bool success = Object::deserialize(node);
    YAML::Node componentsSequence = node["components"];
    for (int i = 0; i < componentsSequence.size(); i++) {
        Component component = componentsSequence[i].as<Component>();
        components.push_back(&component);
    }

    return success;
}