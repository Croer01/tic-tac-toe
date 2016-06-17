//
// Created by Adria on 11/06/2016.
//

#include <SDL_events.h>
#include <SDL.h>
#include <cstdio>
#include <SDL_image.h>
#include "Game.h"
#include "InputManager.h"
#include "ImageManager.h"

Game::Game() {
    window = NULL;
    renderer = NULL;
    running = true;
}

Game::~Game() {
    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
}

//init region
bool Game::init(int screenWidth, int screenHeight) {
    bool success = initSDL() &&
           createWindow(screenWidth, screenHeight) &&
           createRenderer() &&
           initSDLImageModule();

    initManagers();

    return success;
}

bool Game::initSDL() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

bool Game::createWindow(int screenWidth, int screenHeight) {
    bool success = true;

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth,
                              screenHeight, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

bool Game::createRenderer() {
    bool success = true;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

bool Game::initSDLImageModule() {
    bool success = true;

    //Initialize renderer color
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    return success;
}

void Game::initManagers() {
    ImageManager::configManager(renderer);
}
//endregion

void Game::update() {
    InputManager::update();

    if (InputManager::quitPressed())
        running = false;

}

void Game::render() {

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    draw();
    //Update screen
    SDL_RenderPresent(renderer);
}

bool Game::isRunning() {
    return running;
}
