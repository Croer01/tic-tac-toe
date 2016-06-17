#include <SDL.h>
#include "game/GameTicTacToe.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
    GameTicTacToe game;

    if(game.init(SCREEN_WIDTH,SCREEN_HEIGHT)){
        while (game.isRunning()){
            game.update();
            game.render();
        }
    }

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}