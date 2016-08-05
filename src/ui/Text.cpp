//
// Created by Adria on 18/06/2016.
//

#include "Text.h"
#include "../services/GameServices.h"

INIT_METADATA(Text);

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

void Text::render() {
    UIElement::render();
    if (textUpdated) {
        drawContentText();
    }
    if (textToRender != NULL)
        textToRender->draw(renderer, bounds);
}

void Text::serialize(YAML::Node node) const{
    UIElement::serialize(node);
    node["text"] = contentText;
}

bool Text::deserialize(YAML::Node node) {
    bool success = UIElement::deserialize(node);
    setText(node["text"].as<std::string>());

    return success;
}
