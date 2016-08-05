//
// Created by Adria on 27/07/2016.
//

#include "Transform2D.h"

INIT_METADATA(Transform2D);

const SDL_Point &Transform2D::getPosition() const {
    return position;
}

void Transform2D::setPosition(SDL_Point position) {
    this->position = position;
}

const SDL_Point &Transform2D::getScale() const {
    return size;
}

void Transform2D::setSize(SDL_Point scale) {
    this->size = scale;
}

const SDL_Point &Transform2D::getRotation() const {
    return rotation;
}

void Transform2D::setRotation(SDL_Point rotation) {
    this->rotation = rotation;
}

void Transform2D::move(const SDL_Point &movement) {
    this->position.x += movement.x;
    this->position.y += movement.y;
}

void Transform2D::rotate(const SDL_Point &rotation) {
    this->rotation.x = (this->rotation.x + rotation.x) % 360;
    this->rotation.y = (this->rotation.y + rotation.y) % 360;
}

Transform2D::Transform2D() {
    name = "transform2D";
    position = {x:0, y:0};
    rotation = {x:0, y:0};
    size = {x:1, y:1};
}

void Transform2D::serialize(YAML::Node node) const {
    Component::serialize(node);
    node["position"]["x"] = position.x;
    node["position"]["y"] = position.y;

    node["rotation"]["x"] = rotation.x;
    node["rotation"]["y"] = rotation.y;

    node["size"]["x"] = size.x;
    node["size"]["y"] = size.y;
}

bool Transform2D::deserialize(YAML::Node node) {
    bool success = Component::deserialize(node);

    position = {x:node["position"]["x"].as<int>(), y:node["position"]["y"].as<int>()};
    rotation = {x:node["rotation"]["x"].as<int>(), y:node["rotation"]["y"].as<int>()};
    size = {x:node["size"]["x"].as<int>(), y:node["size"]["y"].as<int>()};

    return success;
}

const SDL_Rect Transform2D::getRect() {
    return {x:position.x,y:position.y,w:size.x,h:size.y};
}
