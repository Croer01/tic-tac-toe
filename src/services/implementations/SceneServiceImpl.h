//
// Created by Adria on 16/07/2016.
//

#ifndef SDL_HELLO_WORLD_SCENEMANAGER_H
#define SDL_HELLO_WORLD_SCENEMANAGER_H


#include <map>
#include "../../core/Scene.h"
#include "../interfaces/SceneService.h"

class Game;

class SceneServiceImpl : public SceneService {
    std::vector<Scene *> scenes;
    Scene *currentScene;
    Scene *nextScene;

    void addScene(Scene *scene);

    void load();

public:
    SceneServiceImpl();

    virtual Scene *getCurrentScene();

    virtual bool changeScene(std::string sceneName);

    virtual void initializeNextSceneInSafeMode();

    virtual void update();

    virtual void render();
};


#endif //SDL_HELLO_WORLD_SCENEMANAGER_H
