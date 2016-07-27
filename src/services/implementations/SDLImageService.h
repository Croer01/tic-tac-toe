//
// Created by Adria on 14/06/2016.
//

#ifndef SDL_HELLO_WORLD_IMAGEMANAGER_H
#define SDL_HELLO_WORLD_IMAGEMANAGER_H


#include <map>
#include <SDL_ttf.h>
#include "../../core/Texture.h"
#include "../ImageService.h"

class SDLImageService : public ImageService {
    SDL_Renderer *renderer;
    TTF_Font *font;

    std::map<std::string, Texture *> textureLibrary;

    Texture * createTextureFromFileName(std::string filename);
public:
    SDLImageService(SDL_Renderer *renderer);

    virtual Texture *getTextureByFileName(std::string filename);

    virtual Texture *createTextureFromString(std::string text);
};


#endif //SDL_HELLO_WORLD_IMAGEMANAGER_H
