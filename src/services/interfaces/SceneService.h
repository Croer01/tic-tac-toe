//
// Created by Adria on 06/08/2016.
//

#ifndef TIC_TAC_TOE_SCENESERVICE_H
#define TIC_TAC_TOE_SCENESERVICE_H


#include <string>

class Scene;

class SceneService {
public:
    virtual ~SceneService() { };

    virtual Scene *getCurrentScene() = 0;

    virtual bool changeScene(std::string sceneName) = 0;

    virtual void initializeNextSceneInSafeMode() = 0;

    virtual void update() = 0;

    virtual void render() = 0;
};


#endif //TIC_TAC_TOE_SCENESERVICE_H
