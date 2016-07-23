#include <SDL.h>
#include "core/Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
    Game game;

    if(game.init(SCREEN_WIDTH,SCREEN_HEIGHT)){
        while (game.isRunning()){
            game.update();
            game.render();
            game.changeSceneInSafeMode();
        }
    }
    return 0;
}