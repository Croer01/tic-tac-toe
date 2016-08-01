//
// Created by Adria on 11/06/2016.
//

#include "SceneMetadata.h"
#include "../core/game-objects/WorldElement.h"

#include <boost/archive/tmpdir.hpp>

void SceneMetadata::init() {
    WorldElement element("");
    element.setName("awsome name");
    element.addComponent(new Component());
//    std::string filename(boost::archive::tmpdir());
//    filename += "/demofile.txt";
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, boost::archive::tmpdir());

    Serializer::save<WorldElement>(&element);
}

void SceneMetadata::update() {

}

void SceneMetadata::render() {

}















