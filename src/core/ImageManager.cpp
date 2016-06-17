//
// Created by Adria on 14/06/2016.
//

#include <SDL_image.h>
#include "ImageManager.h"

ImageManager *ImageManager::instance = NULL;

ImageManager::ImageManager(SDL_Renderer *renderer) {
    this->renderer = renderer;
}
//region static
Texture *ImageManager::getTextureByFileName(std::string filename) {
    return instance->instance_GetTextureByFileName(filename);
}

void ImageManager::configManager(SDL_Renderer *renderer) {
    instance = new ImageManager(renderer);
}
//endregion

Texture *ImageManager::instance_GetTextureByFileName(std::string filename) {
    Texture *texture = NULL;

    auto iterator = textureLibrary.find(filename);
    if (iterator == textureLibrary.end()) {
        texture = instance_CreateTextureFromFileName(filename);
        if (texture != NULL) {
            textureLibrary[filename] = texture;
        }
    }
    else {
        texture = iterator->second;
    }

    return texture;
}

Texture *ImageManager::instance_CreateTextureFromFileName(std::string filename) {
    Texture *texture = NULL;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(filename.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
    }
    else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        SDL_Texture *textureLoaded = NULL;

        //Create texture from surface pixels
        textureLoaded = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (textureLoaded == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
        }
        else {
            //Get image dimensions
            texture = new Texture(textureLoaded, loadedSurface->w, loadedSurface->h);
            printf("Texture \"%s\" loaded, dimensions: %d x %d\n", filename.c_str(), texture->getWidth(),
                   texture->getHeight());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success

    return texture;
}





