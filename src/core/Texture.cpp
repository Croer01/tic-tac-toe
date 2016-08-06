//
// Created by Adria on 11/06/2016.
//

#include <SDL_image.h>
#include "Texture.h"
#include "../services/GameServices.h"

Texture::Texture(SDL_Texture *texture, int width, int height) {
    //Initialize
    mTexture = texture;
    mWidth = width;
    mHeight = height;
}

Texture::~Texture() {
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
}

int Texture::getWidth() {
    return mWidth;
}

int Texture::getHeight() {
    return mHeight;
}

void Texture::draw(SDL_Rect size) {
    SDL_RenderCopy(GameServices::getScreen()->gerRenderer(), mTexture, NULL, &size);
}

void Texture::draw(SDL_Rect size, SDL_Rect clip, bool preserveAspect) {
    if(preserveAspect){
        size.w = clip.w/clip.h * size.h;
    }

    SDL_RenderCopy(GameServices::getScreen()->gerRenderer(), mTexture, &clip, &size);
}



