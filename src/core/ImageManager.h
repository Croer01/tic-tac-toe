//
// Created by Adria on 14/06/2016.
//

#ifndef SDL_HELLO_WORLD_IMAGEMANAGER_H
#define SDL_HELLO_WORLD_IMAGEMANAGER_H


#include <map>
#include "Texture.h"

class ImageManager {
    SDL_Renderer *renderer;

    //static
    static ImageManager *instance;

    std::map<std::string, Texture *> textureLibrary;

    ImageManager(SDL_Renderer *renderer);

    Texture *instance_CreateTextureFromFileName(std::string filename);

    Texture *instance_GetTextureByFileName(std::string filename);

public:
    static Texture *getTextureByFileName(std::string filename);

    static void configManager(SDL_Renderer *renderer);
};


#endif //SDL_HELLO_WORLD_IMAGEMANAGER_H
