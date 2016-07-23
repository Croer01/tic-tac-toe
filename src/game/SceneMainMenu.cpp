//
// Created by Adria on 18/06/2016.
//

#include "SceneMainMenu.h"

void SceneMainMenu::init() {
    startText = new Text(renderer,{0,0,200,100});
    startText->setText("Start Game");
    startText->addOnClickHandler([=](){
        game->changeScene("main Game");
    });
}

void SceneMainMenu::update() {
startText->update();
}

void SceneMainMenu::render() {
startText->render();
}





