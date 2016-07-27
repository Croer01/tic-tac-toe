//
// Created by Adria on 27/07/2016.
//

#ifndef SDL_HELLO_WORLD_GAMESERVICES_H
#define SDL_HELLO_WORLD_GAMESERVICES_H


#include "ImageService.h"
#include "InputService.h"
#include "null-services/NullImageService.h"
#include "null-services/NullInputService.h"

class GameServices {
private:
    static ImageService *imageService;
    static InputService *inputService;
    static NullImageService nullImageService;
    static NullInputService nullInputService;

public:
    static void initialize();

    static void provide(ImageService *imageService);

    static void provide(InputService *inputService);

    static ImageService *getImage();

    static InputService *getInput();
};


#endif //SDL_HELLO_WORLD_GAMESERVICES_H
