//
// Created by Adria on 17/06/2016.
//

#ifndef SDL_HELLO_WORLD_SCENE_H
#define SDL_HELLO_WORLD_SCENE_H


#include <SDL_render.h>
#include "Game.h"
#include "Object.h"
#include "game-objects/Element.h"

class Game;

class Scene : public Object {
CREATE_METADATA(Scene);
    std::vector<Element*> elements;
protected:
    SDL_Renderer *renderer;
    Game *game;

public:

    Scene() { };

    Scene(Game *game, SDL_Renderer *renderer);

    virtual void init();

    virtual void update();

    virtual void render();

    void setRenderer(SDL_Renderer *renderer);

    void setGame(Game *game);

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


};


#endif //SDL_HELLO_WORLD_SCENE_H
