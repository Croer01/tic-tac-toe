//
// Created by Adria on 14/06/2016.
//

#include <SDL_image.h>
#include <SDL_ttf.h>
#include "SDLImageService.h"

SDLImageService::SDLImageService(SDL_Renderer *renderer) : ImageService(){
    this->renderer = renderer;
    this->font = TTF_OpenFont("assets/fonts/Pacifico.ttf", 28);
}

Texture * SDLImageService::getTextureByFileName(std::string filename) {
    Texture *texture = NULL;

    auto iterator = textureLibrary.find(filename);
    if (iterator == textureLibrary.end()) {
        texture = createTextureFromFileName(filename);
        if (texture != NULL) {
            textureLibrary[filename] = texture;
        }
    }
    else {
        texture = iterator->second;
    }

    return texture;
}

Texture * SDLImageService::createTextureFromString(std::string text) {
    Texture *texture = NULL;

    //Render text surface
    SDL_Surface *loadedSurface = TTF_RenderText_Blended(font, text.c_str(), {0, 0, 0});
    if (loadedSurface == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER,"Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else {
        SDL_Texture *textureLoaded = NULL;

        //Create texture from surface pixels
        textureLoaded = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (textureLoaded == NULL) {
            SDL_LogError(SDL_LOG_CATEGORY_RENDER,"Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else {
            //Get image dimensions
            texture = new Texture(textureLoaded, loadedSurface->w, loadedSurface->h);
        }

        //Get rid of old surface
        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}

Texture * SDLImageService::createTextureFromFileName(std::string filename) {
    Texture *texture = NULL;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(filename.c_str());
    if (loadedSurface == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER,"Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
    }
    else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        SDL_Texture *textureLoaded = NULL;

        //Create texture from surface pixels
        textureLoaded = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (textureLoaded == NULL) {
            SDL_LogError(SDL_LOG_CATEGORY_RENDER,"Unable to create texture from %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
        }
        else {
            //Get image dimensions
            texture = new Texture(textureLoaded, loadedSurface->w, loadedSurface->h);
            SDL_LogInfo(SDL_LOG_CATEGORY_RENDER,"Texture \"%s\" loaded, dimensions: %d x %d\n", filename.c_str(), texture->getWidth(),
                        texture->getHeight());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return texture;
}



