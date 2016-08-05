//
// Created by Adria on 27/07/2016.
//
#include "GameServices.h"

ImageService *GameServices::imageService = new NullImageService();
InputService *GameServices::inputService = new NullInputService();
CursorService *GameServices::cursorService = new NullCursorService();

void GameServices::provide(ImageService *service) {
    if(service != NULL){
        imageService = service;
    }
    else{
        imageService = new NullImageService();
    }
}

void GameServices::provide(InputService *service) {
    if(service != NULL){
        inputService = service;
    }
    else{
        inputService = new NullInputService();
    }
}

void GameServices::provide(CursorService *service){
    if(service != NULL){
        cursorService = service;
    }
    else{
        cursorService = new NullCursorService();
    }
}

ImageService *GameServices::getImage() {
    return imageService;
}

InputService *GameServices::getInput() {
    return inputService;
}

CursorService *GameServices::getCursor() {
    return cursorService;
}









