//
// Created by Adria on 04/08/2016.
//

#include <boost/archive/tmpdir.hpp>
#include "SaveSceneButton.h"
#include "../serialization/Serializer.h"
#include "../services/GameServices.h"


INIT_METADATA(SaveSceneButton);

void SaveSceneButton::init() {
    Text::init();
    std::string filename(boost::archive::tmpdir());
    filename += "\\currentScene";
    addOnClickHandler([filename](){
        //save current scene
        std::string fileSaved = Serializer::save<Scene>(GameServices::getScenes()->getCurrentScene(), filename);
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"save current scene state on:%s", fileSaved.c_str());
    });
}
