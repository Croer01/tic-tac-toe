//
// Created by Adria on 18/06/2016.
//

#ifndef SDL_HELLO_WORLD_SCENEMAINMENU_H
#define SDL_HELLO_WORLD_SCENEMAINMENU_H


#include "../core/Scene.h"
#include "../ui/Text.h"

class SceneMainMenu : public Scene {
    Text *startText;

public:
    SceneMainMenu(Game *game, SDL_Renderer *renderer) : Scene(game, renderer) { }

    void init();

    void update();

    void render();

};


#endif //SDL_HELLO_WORLD_SCENEMAINMENU_H
