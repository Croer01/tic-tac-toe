//
// Created by Adria on 06/08/2016.
//

#include "ScreenServiceImpl.h"

ScreenServiceImpl::ScreenServiceImpl(SDL_Renderer *renderer) {
    this->renderer = renderer;
    SDL_GetRendererOutputSize(renderer, &width, &height);
}

SDL_Renderer *ScreenServiceImpl::gerRenderer() const {
    return renderer;
}

int ScreenServiceImpl::getWidth() const {
    return width;
}

int ScreenServiceImpl::getHeight() const {
    return height;
}





