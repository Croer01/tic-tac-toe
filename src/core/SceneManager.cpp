//
// Created by Adria on 16/07/2016.
//

#include "SceneManager.h"

SceneManager::SceneManager() {
    currentScene = NULL;
    nextScene = NULL;
}

void SceneManager::registerScene(std::string name, Scene *scene) {
    scenes[name] = scene;
}

Scene *SceneManager::getCurrentScene() {
    return currentScene;
}

bool SceneManager::changeScene(std::string sceneName) {
    bool isChanged = false;
    auto search = scenes.find(sceneName);
    if (search != scenes.end()) {
        if (currentScene == NULL) {
            currentScene = search->second;
        }
        else {
            nextScene = search->second;
        }
        isChanged = true;
    }

    return isChanged;
}

void SceneManager::initializeNextSceneInSafeMode() {
    if (nextScene != NULL) {
        currentScene = nextScene;
        currentScene->init();
        nextScene = NULL;
    }
}


