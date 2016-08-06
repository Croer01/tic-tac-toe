//
// Created by Adria on 06/08/2016.
//

#ifndef TIC_TAC_TOE_NULLSERIALIZERCLASS_H
#define TIC_TAC_TOE_NULLSERIALIZERCLASS_H


#include <string>

class Scene;

class NullSceneService : public SceneService{
public:
    virtual Scene *getCurrentScene() {return NULL;};

    virtual bool changeScene(std::string sceneName) {return false;};

    virtual void initializeNextSceneInSafeMode() {};

    virtual void update() {};

    virtual void render() {};
};


#endif //TIC_TAC_TOE_NULLSERIALIZERCLASS_H
