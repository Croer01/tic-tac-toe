//
// Created by Adria on 28/07/2016.
//

#include "WorldElement.h"


INIT_METADATA(WorldElement);

WorldElement::WorldElement(const std::string &name) : Element(name) {
}

bool WorldElement::deserialize(YAML::Node node) {
    bool success = Element::deserialize(node);
    transform = (Transform2D *) getComponent("transform2D");
    return success;
}

Transform2D *WorldElement::getTransform() {
    return transform;
}


