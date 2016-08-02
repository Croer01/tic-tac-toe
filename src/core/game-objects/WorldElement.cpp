//
// Created by Adria on 28/07/2016.
//

#include "WorldElement.h"
#include "Transform2D.h"

INIT_INSTANTIATOR(WorldElement);

WorldElement::WorldElement(const std::string &name) : Element(name) {
    addComponent(new Transform2D());
}

