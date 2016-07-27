//
// Created by Adria on 18/06/2016.
//

#include "Text.h"
#include "../services/GameServices.h"

Text::Text(SDL_Renderer *renderer, SDL_Rect bounds) : UIElement(renderer, bounds) {
    contentText = "";
}

Text::~Text(){
    delete textToRender;
    textToRender = NULL;
}

void Text::setText(std::string text) {
    contentText = text;
    textUpdated = true;
}

const std::string Text::getText() {
    return contentText;
}

void Text::drawContentText() {
    textToRender = GameServices::getImage()->createTextureFromString(contentText);
    textUpdated = false;
}

void Text::init() {

}

void Text::update(){
    UIElement::update();
}

void Text::render() {
    if (textUpdated) {
        drawContentText();
    }
    if(textToRender != NULL)
    textToRender->draw(renderer, {bounds.x,bounds.y,textToRender->getWidth(),textToRender->getHeight()},bounds,true);
}
