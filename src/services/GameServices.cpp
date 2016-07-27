//
// Created by Adria on 27/07/2016.
//
#include "GameServices.h"

ImageService *GameServices::imageService = NULL;
InputService *GameServices::inputService = NULL;
NullImageService GameServices::nullImageService;
NullInputService GameServices::nullInputService;

void GameServices::initialize() {
    imageService = &nullImageService;
    inputService = &nullInputService;
}

void GameServices::provide(ImageService *service) {
    if(service != NULL){
        imageService = service;
    }
    else{
        imageService = &nullImageService;
    }
}

void GameServices::provide(InputService *service) {
    if(service != NULL){
        inputService = service;
    }
    else{
        inputService = &nullInputService;
    }
}

ImageService *GameServices::getImage() {
    return imageService;
}

InputService *GameServices::getInput() {
    return inputService;
}









