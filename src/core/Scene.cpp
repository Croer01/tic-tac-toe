//
// Created by Adria on 17/06/2016.
//

#include "Scene.h"

INIT_METADATA(Scene);
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
        addElement((Element*)Serializer::Metadata::deserialize(elementsSequence[i]));
    }

    return success;
}

void Scene::init(Game *game,SDL_Renderer *renderer) {
    for (Element *element: elements) {
        element->init(game,renderer);
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

void Scene::addElement(Element *element) {
    elements.push_back(element);
}




