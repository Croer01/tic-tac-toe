//
// Created by Adria on 18/06/2016.
//

#ifndef SDL_HELLO_WORLD_UIELEMENT_H
#define SDL_HELLO_WORLD_UIELEMENT_H


#include <SDL_rect.h>
#include <SDL_render.h>
#include <functional>

class UIElement {
protected:
    SDL_Rect bounds;
    SDL_Renderer *renderer;
    std::function<void()> onClickCallback;

    void clickEvent();

public:
    UIElement(SDL_Renderer *renderer, SDL_Rect bounds);

    virtual ~UIElement() { };

    virtual void init() = 0;

    virtual void update();

    virtual void render() = 0;

    void addOnClickHandler(std::function<void()> handler);
};


#endif //SDL_HELLO_WORLD_UIELEMENT_H
