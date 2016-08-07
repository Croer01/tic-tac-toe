//
// Created by Adria on 27/07/2016.
//

#ifndef SDL_HELLO_WORLD_IMAGESERVICE_H
#define SDL_HELLO_WORLD_IMAGESERVICE_H


#include <string>
#include "../../core/Texture.h"
#include "../../components/Font.h"

class ImageService {
public:
    virtual ~ImageService() { }

    virtual Texture *getTextureByFileName(std::string filename) = 0;

    virtual Texture *createTextureFromString(Font* font, std::string text) = 0;
};


#endif //SDL_HELLO_WORLD_IMAGESERVICE_H
