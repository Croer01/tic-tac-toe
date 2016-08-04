//
// Created by Adria on 16/07/2016.
//

#ifndef SDL_HELLO_WORLD_SCENEMANAGER_H
#define SDL_HELLO_WORLD_SCENEMANAGER_H


#include <map>
#include "Scene.h"

class Scene;
class SceneManager {
    std::map<std::string, Scene *> scenes;
    Scene *currentScene;
    Scene *nextScene;

public:
    SceneManager(std::string scenePath);

    Scene *getCurrentScene();

    bool changeScene(std::string sceneName);

    void initializeNextSceneInSafeMode();
};


#endif //SDL_HELLO_WORLD_SCENEMANAGER_H
