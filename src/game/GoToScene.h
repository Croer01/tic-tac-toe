//
// Created by Adria on 05/08/2016.
//

#ifndef TIC_TAC_TOE_GOTOSCENE_H
#define TIC_TAC_TOE_GOTOSCENE_H


#include "../game-objects/components/Component.h"

class GoToScene : public Component {
CREATE_METADATA(GoToScene);
    std::string sceneName;
public:
    GoToScene() : Component() { };

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);

    virtual void init();


};

#endif //TIC_TAC_TOE_GOTOSCENE_H
