//
// Created by Adria on 11/06/2016.
//

#ifndef SDL_HELLO_WORLD_GAME_H
#define SDL_HELLO_WORLD_GAME_H


#include <SDL_video.h>
#include <SDL_render.h>
#include <vector>
#include <memory>
#include "SceneManager.h"

class SceneManager;
class Element;
class Scene;

class Game {
    Element* reset_button;
    bool initSDL_ImageModule();

    bool createRenderer();

    bool createWindow(int screenWidth, int screenHeight);

    bool initSDL();

    bool initSDL_TTF_Module();

    bool initSceneManager();

protected:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
    SceneManager *sceneManager;

    virtual void initGameServices();

public:
    Game();

    virtual ~Game();

    virtual bool init(int screenWidth, int screenHeight);

    virtual void update();

    void render();

    bool isRunning();

    void exit();

    bool changeScene(std::string sceneName);

    void changeSceneInSafeMode();

    void reloadScene();

    Scene *getCurrentScene() const;
};


#endif //SDL_HELLO_WORLD_GAME_H
