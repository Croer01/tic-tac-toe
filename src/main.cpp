#include <SDL.h>
#include "core/Game.h"
#include "core/Logger.h"
#include "services/GameServices.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
    Game game;
    Logger logger(SDL_LOG_PRIORITY_VERBOSE);
    logger.open("game.log");
    if (game.init(SCREEN_WIDTH, SCREEN_HEIGHT)) {
        while (game.isRunning()) {
            game.update();
            game.render();
            GameServices::getScenes()->initializeNextSceneInSafeMode();
        }
    }
    logger.close();
    return 0;
}
