//
// Created by Adria on 05/08/2016.
//

#include "GoToScene.h"
#include "../ui/Button.h"
#include "../services/GameServices.h"

INIT_METADATA(GoToScene);

void GoToScene::init() {
    Component::init();
    Button *button = (Button *) element->getComponent("button");
    button->addOnClickHandler([=]() {
        GameServices::getScenes()->changeScene(sceneName);
    });
}

bool GoToScene::deserialize(YAML::Node node) {
    bool success = Component::deserialize(node);
    sceneName = node["sceneName"].as<std::string>();
    return success;
}

void GoToScene::serialize(YAML::Node node) const {
    Component::serialize(node);
    node["sceneName"] = sceneName;
}
