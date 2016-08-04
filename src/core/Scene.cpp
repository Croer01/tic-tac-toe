//
// Created by Adria on 17/06/2016.
//

#include "Scene.h"

INIT_METADATA(Scene);

Scene::Scene(Game *game, SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->game = game;
}


void Scene::setRenderer(SDL_Renderer *renderer) {
    Scene::renderer = renderer;
}

void Scene::setGame(Game *game) {
    Scene::game = game;
}

void Scene::serialize(YAML::Node node) const {
    Object::serialize(node);
    for (Element *element: elements) {
        node["elements"].push_back(Serializer::Metadata::serialize(element));
    }
}

bool Scene::deserialize(YAML::Node node) {
    bool success = Object::deserialize(node);
    YAML::Node elementsSequence = node["elements"];
    for (int i = 0; i < elementsSequence.size(); i++) {
        Element* element = (Element*)Serializer::Metadata::deserialize(elementsSequence[i]);
        elements.push_back(element);
    }

    return success;
}

void Scene::init() {
    for (Element *element: elements) {
        element->init();
    }
}

void Scene::update() {
    for (Element *element: elements) {
        element->update();
    }
}

void Scene::render() {
    for (Element *element: elements) {
        element->render();
    }
}




