//
// Created by Adria on 27/07/2016.
//

#ifndef SDL_HELLO_WORLD_GAMESERVICES_H
#define SDL_HELLO_WORLD_GAMESERVICES_H

#include "null-services/NullImageService.h"
#include "null-services/NullInputService.h"
#include "null-services/NullCursorService.h"

class GameServices {
private:
    static ImageService *imageService;
    static InputService *inputService;
    static CursorService *cursorService;

public:
    static void provide(ImageService *service);

    static void provide(InputService *service);

    static void provide(CursorService *service);

    static ImageService *getImage();

    static InputService *getInput();

    static CursorService *getCursor();
};


#endif //SDL_HELLO_WORLD_GAMESERVICES_H
