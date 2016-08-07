//
// Created by Adria on 14/06/2016.
//

#ifndef SDL_HELLO_WORLD_IMAGEMANAGER_H
#define SDL_HELLO_WORLD_IMAGEMANAGER_H


#include <map>
#include <SDL_ttf.h>
#include "../../core/Texture.h"
#include "../interfaces/ImageService.h"
#include "../../components/Font.h"

class SDLImageServiceImpl : public ImageService {
    SDL_Renderer *renderer;

    std::map<std::string, Texture *> textureLibrary;

    Texture * createTextureFromFileName(std::string filename);
public:
    SDLImageServiceImpl(SDL_Renderer *renderer);

    virtual Texture *getTextureByFileName(std::string filename);

    virtual Texture *createTextureFromString(Font* font,std::string text);
};


#endif //SDL_HELLO_WORLD_IMAGEMANAGER_H
