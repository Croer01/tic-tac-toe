//
// Created by Adria on 27/07/2016.
//

#ifndef SDL_HELLO_WORLD_IMAGESERVICE_H
#define SDL_HELLO_WORLD_IMAGESERVICE_H


#include <string>
#include "../../core/Texture.h"

class ImageService {
public:
    virtual ~ImageService() { }

    virtual Texture *getTextureByFileName(std::string filename) = 0;

    virtual Texture *createTextureFromString(std::string text) = 0;
};


#endif //SDL_HELLO_WORLD_IMAGESERVICE_H
