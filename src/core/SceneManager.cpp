//
// Created by Adria on 16/07/2016.
//

#include "SceneManager.h"
#include "../serialization/Serializer.h"

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <SDL_filesystem.h>

SceneManager::SceneManager(std::string scenePath, Game *game, SDL_Renderer *renderer) {
    this->game = game;
    this->renderer = renderer;
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
                addScene(sceneLoaded);
            }

            nextScene = scenes.begin()->second;
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
    }else{
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "scenes \"%s\" not exist", sceneName.c_str());
    }

    return isChanged;
}

void SceneManager::initializeNextSceneInSafeMode() {
    if (nextScene != NULL) {
        currentScene = nextScene;
        currentScene->init(game,renderer);
        nextScene = NULL;
    }
}

void SceneManager::addScene(Scene *scene) {
    scenes[scene->getName()] = scene;
}

void SceneManager::update() {
if(currentScene != NULL)
    currentScene->update();
}

void SceneManager::render() {
    if(currentScene != NULL)
        currentScene->render();
}






