//
// Created by Adria on 04/08/2016.
//

#include <boost/archive/tmpdir.hpp>
#include "SaveSceneButton.h"
#include "../serialization/Serializer.h"

INIT_METADATA(SaveSceneButton);

void SaveSceneButton::init(Game *game, SDL_Renderer *renderer) {
    Text::init(game, renderer);
    std::string filename(boost::archive::tmpdir());
    filename += "\\currentScene";
    addOnClickHandler([game,filename](){
        //save current scene
        Serializer::save<Scene>(game->getCurrentScene(), filename);
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"save current scene state on:%s.yaml", filename.c_str());
    });
}
