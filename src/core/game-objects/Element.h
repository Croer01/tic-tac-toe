//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_ELEMENT_H
#define TIC_TAC_TOE_ELEMENT_H


#include <vector>
#include "Component.h"
#include "../Object.h"
#include "../Game.h"
class Game;
class Element : public Object {
CREATE_METADATA(Element);
protected:
    std::vector<Component *> components;
    Game *game;
    SDL_Renderer *renderer;
public:
    Element() { };

    Element(std::string name);

    Component *getComponent(std::string componentName);

    void addComponent(Component *component);

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


    virtual void init(Game *game,SDL_Renderer *renderer);

    virtual void update();

    virtual void render();

};

#endif //TIC_TAC_TOE_ELEMENT_H
