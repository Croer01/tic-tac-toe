//
// Created by Adria on 16/07/2016.
//

#include "SceneManager.h"
#include "../serialization/Serializer.h"

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <SDL_filesystem.h>

SceneManager::SceneManager(std::string scenePath) {
    currentScene = NULL;
    nextScene = NULL;

    if (!scenePath.empty()) {
        namespace fs = boost::filesystem;

        fs::path files(SDL_GetBasePath());
        files /= scenePath;
        if (!fs::exists(files)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "scenes path not found: %s", files.string().c_str());
        }
        else {
            fs::recursive_directory_iterator end;

            for (fs::recursive_directory_iterator i(files); i != end; ++i) {
                fs::path path = *i;
                Scene *sceneLoaded = Serializer::load<Scene>(path.string());
                scenes[sceneLoaded->getName()] = sceneLoaded;
            }

            currentScene = scenes.begin()->second;
        }
    }
}

Scene *SceneManager::getCurrentScene() {
    return currentScene;
}

bool SceneManager::changeScene(std::string sceneName) {
    bool isChanged = false;
    auto search = scenes.find(sceneName);
    if (search != scenes.end()) {
        nextScene = search->second;
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
