//
// Created by Adria on 11/06/2016.
//

#include "SceneMetadata.h"
#include "../core/game-objects/WorldElement.h"
#include "../serialization/Serializer.h"

#include <boost/archive/tmpdir.hpp>

void SceneMetadata::init() {
    //directory
    std::string filename(boost::archive::tmpdir());
    filename += "\\demofile";
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "%s.yaml", filename.c_str());

    //save element
    WorldElement element("");
    element.setName("awesome name");
    element.addComponent(new Component());
    Serializer::save<WorldElement>(&element, filename);

    //load element
    WorldElement *elementLoaded = Serializer::load<WorldElement>(filename);
//    Serializer::save<WorldElement>(elementLoaded, filename);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "loaded name: %s", elementLoaded->getComponent("transform2D")->getName().c_str());

}

void SceneMetadata::update() {

}

void SceneMetadata::render() {

}















