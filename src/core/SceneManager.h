//
// Created by Adria on 16/07/2016.
//

#ifndef SDL_HELLO_WORLD_SCENEMANAGER_H
#define SDL_HELLO_WORLD_SCENEMANAGER_H


#include <map>
#include "Scene.h"

class Scene;
class Game;

class SceneManager {
    std::map<std::string, Scene *> scenes;
    Scene *currentScene;
    Scene *nextScene;

    Game *game;
    SDL_Renderer *renderer;

    void addScene(Scene *scene);

public:
    SceneManager(std::string scenePath, Game *game, SDL_Renderer *renderer);

    Scene *getCurrentScene();

    bool changeScene(std::string sceneName);

    void initializeNextSceneInSafeMode();

    void update();

    void render();
};


#endif //SDL_HELLO_WORLD_SCENEMANAGER_H
