//
// Created by Adria on 17/06/2016.
//

#ifndef SDL_HELLO_WORLD_SCENE_H
#define SDL_HELLO_WORLD_SCENE_H


#include <SDL_render.h>
#include "Game.h"
#include "Object.h"
#include "../game-objects/elements/Element.h"

class Game;
class Element;

class Scene : public Object {
CREATE_METADATA(Scene);
    std::vector<Element*> elements;

    void addElement(Element* element);
public:

    Scene() { };

    void init(Game *game,SDL_Renderer *renderer);

    void update();

    void render();

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


};


#endif //SDL_HELLO_WORLD_SCENE_H
