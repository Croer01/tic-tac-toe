//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_NULLIMAGESERVICE_H
#define TIC_TAC_TOE_NULLIMAGESERVICE_H


#include "../interfaces/ImageService.h"

class NullImageService : public ImageService {
public:
    virtual Texture *getTextureByFileName(std::string filename) { return NULL; };

    virtual void configManager(SDL_Renderer *renderer) { };

    virtual Texture *createTextureFromString(std::string text) { return NULL; };
};


#endif //TIC_TAC_TOE_NULLIMAGESERVICE_H
