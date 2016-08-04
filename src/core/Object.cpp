//
// Created by Adria on 27/07/2016.
//

#include "Object.h"


INIT_METADATA(Object);

void Object::serialize(YAML::Node node) const {
    node["name"] = name;
}

bool Object::deserialize(YAML::Node node) {
    name = node["name"].as<std::string>();
    return true;
}



