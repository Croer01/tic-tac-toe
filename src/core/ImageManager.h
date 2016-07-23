//
// Created by Adria on 14/06/2016.
//

#ifndef SDL_HELLO_WORLD_IMAGEMANAGER_H
#define SDL_HELLO_WORLD_IMAGEMANAGER_H


#include <map>
#include <SDL_ttf.h>
#include "Texture.h"

class ImageManager {
    SDL_Renderer *renderer;
    TTF_Font *font;

    //static
    static ImageManager *instance;

    std::map<std::string, Texture *> textureLibrary;

    ImageManager(SDL_Renderer *renderer);

    Texture *instance_CreateTextureFromFileName(std::string filename);

    Texture *instance_GetTextureByFileName(std::string filename);

    Texture *instance_CreateTextureFromString(std::string text);
public:
    static Texture *getTextureByFileName(std::string filename);

    static void configManager(SDL_Renderer *renderer);

    static Texture *createTextureFromString(std::string text);
};


#endif //SDL_HELLO_WORLD_IMAGEMANAGER_H
