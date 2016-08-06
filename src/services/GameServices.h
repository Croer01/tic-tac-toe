//
// Created by Adria on 27/07/2016.
//

#ifndef SDL_HELLO_WORLD_GAMESERVICES_H
#define SDL_HELLO_WORLD_GAMESERVICES_H

#include "interfaces/SceneService.h"
#include "null-services/NullImageService.h"
#include "null-services/NullInputService.h"
#include "null-services/NullCursorService.h"
#include "null-services/NullSceneService.h"
#include "null-services/NullScreenService.h"

class GameServices {
private:
    static ImageService *imageService;
    static InputService *inputService;
    static CursorService *cursorService;
    static SceneService *sceneService;
    static ScreenService *screenService;

public:
    static void provide(ImageService *service);

    static void provide(InputService *service);

    static void provide(CursorService *service);

    static void provide(SceneService *service);

    static void provide(ScreenService *service);

    static ImageService *getImage();

    static InputService *getInput();

    static CursorService *getCursor();

    static SceneService *getScenes();

    static ScreenService *getScreen();
};


#endif //SDL_HELLO_WORLD_GAMESERVICES_H
