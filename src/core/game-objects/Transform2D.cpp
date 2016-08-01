//
// Created by Adria on 27/07/2016.
//

#include "Transform2D.h"

const SDL_Point &Transform2D::getPosition() const {
    return position;
}

void Transform2D::setPosition(const SDL_Point &position) {
    this->position = position;
}

const SDL_Point &Transform2D::getScale() const {
    return scale;
}

void Transform2D::setScale(const SDL_Point &scale) {
    this->scale = scale;
}

const SDL_Point &Transform2D::getRotation() const {
    return rotation;
}

void Transform2D::setRotation(const SDL_Point &rotation) {
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
    scale = {x:1, y:1};
}

void Transform2D::serialize(YAML::Node node) const {
    Component::serialize(node);
    node["position"]["x"] = position.x;
    node["position"]["y"] = position.y;

    node["rotation"]["x"] = rotation.x;
    node["rotation"]["y"] = rotation.y;

    node["scale"]["x"] = scale.x;
    node["scale"]["y"] = scale.y;
}

bool Transform2D::deserialize(YAML::Node node) {
    bool success = Component::deserialize(node);

    position = {x:node["position"]["x"].as<int>(), y:node["position"]["y"].as<int>()};
    rotation = {x:node["rotation"]["x"].as<int>(), y:node["rotation"]["y"].as<int>()};
    scale = {x:node["scale"]["x"].as<int>(), y:node["scale"]["y"].as<int>()};

    return success;
}