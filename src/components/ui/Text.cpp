//
// Created by Adria on 18/06/2016.
//

#include "Text.h"
#include "../../services/GameServices.h"
#include "../Transform2D.h"

INIT_METADATA(Text);

Text::Text() : Component() {
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
    textToRender = GameServices::getImage()->createTextureFromString(fontComponent,contentText);
    textUpdated = false;
}

void Text::init() {
    Component::init();
    fontComponent = (Font*)element->getComponent("font");
}

void Text::render() {
    Component::render();
    if (textUpdated) {
        drawContentText();
    }
    if (textToRender != NULL)
        textToRender->draw(element->getTransform()->getRect());
}

void Text::serialize(YAML::Node node) const{
    Component::serialize(node);
    node["text"] = contentText;
}

bool Text::deserialize(YAML::Node node) {
    bool success = Component::deserialize(node);
    setText(node["text"].as<std::string>());

    return success;
}
