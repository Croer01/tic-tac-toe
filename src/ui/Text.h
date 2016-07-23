//
// Created by Adria on 18/06/2016.
//

#ifndef SDL_HELLO_WORLD_TEXT_H
#define SDL_HELLO_WORLD_TEXT_H


#include <string>
#include "UIElement.h"
#include "../core/Texture.h"

class Text : public UIElement {
    std::string contentText;
    Texture *textToRender;
    bool textUpdated;

    void drawContentText();

public:
    Text(SDL_Renderer *renderer, SDL_Rect bounds);

    void setText(std::string text);

    const std::string getText();

    //UIElement implementation
    void render();

    ~Text();

    void init();

    void update();


};


#endif //SDL_HELLO_WORLD_TEXT_H
