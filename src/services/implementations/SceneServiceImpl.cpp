//
// Created by Adria on 16/07/2016.
//

#include "SceneServiceImpl.h"
#include "../../serialization/Serializer.h"
#include "../GameServices.h"

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <SDL_filesystem.h>
#include <SDL_log.h>

void SceneServiceImpl::load(){
    currentScene = NULL;
    nextScene = NULL;

    namespace fs = boost::filesystem;
    fs::path scenesConfigFile(SDL_GetBasePath());
    scenesConfigFile /= "Data/Config";
    scenesConfigFile /= "scenes.config";

    if (!fs::exists(scenesConfigFile)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "scenes config not found: %s", scenesConfigFile.string().c_str());
    }
    else {
        YAML::Node sceneList = YAML::LoadFile(scenesConfigFile.string());

        for (YAML::const_iterator scenePath = sceneList.begin(); scenePath != sceneList.end(); scenePath++) {
            Scene *sceneLoaded = Serializer::load<Scene>(scenePath->as<std::string>());
            addScene(sceneLoaded);
        }

        nextScene = scenes[0];
    }
}

SceneServiceImpl::SceneServiceImpl() {
    load();
}

Scene *SceneServiceImpl::getCurrentScene() {
    return currentScene;
}

bool SceneServiceImpl::changeScene(std::string sceneName) {
    bool isChanged = false;
    std::vector<Scene*>::iterator search = scenes.end();

    if (!sceneName.empty()) {
        search = std::find_if(scenes.begin(), scenes.end(), [sceneName](Scene* scene) {
            return sceneName.compare(scene->getName())==0;
        });

    }

    if (search != scenes.end()) {
        nextScene = *search;
        isChanged = true;
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "scenes \"%s\" not exist", sceneName.c_str());
    }

    return isChanged;
}

void SceneServiceImpl::initializeNextSceneInSafeMode() {
    if (nextScene != NULL) {
        currentScene = nextScene;
        currentScene->init();
        nextScene = NULL;
    }
}

void SceneServiceImpl::addScene(Scene *scene) {
    scenes.push_back(scene);
}

void SceneServiceImpl::update() {
    if (currentScene != NULL)
        currentScene->update();

    if(GameServices::getInput()->isKeyDown(SDLK_r)){
        currentScene = NULL;
        nextScene = NULL;
        for(Scene* scene:scenes){
            delete scene;
        }
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"reload all scenes");
        scenes.clear();
        load();
    }
}

void SceneServiceImpl::render() {
    if (currentScene != NULL)
        currentScene->render();
}






