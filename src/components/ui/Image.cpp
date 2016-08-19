//
// Created by Adria on 08/08/2016.
//

#include "Image.h"
#include "../../services/GameServices.h"
#include "../../components/Transform2D.h"

INIT_METADATA(Image);

Image::Image() : Component(){
    image = NULL;
}

Image::~Image() {
    delete image;
    image = NULL;
}

void Image::init() {
    Component::init();
    //Initialize
    image= GameServices::getImage()->getTextureByFileName(fileName);
}

int Image::getImageWidth() {
    return width;
}

int Image::getImageHeight() {
    return height;
}

void Image::serialize(YAML::Node node) const {
    Component::serialize(node);
    node["fileName"]= fileName;
    node["width"] = width;
    node["height"] = height;
}

bool Image::deserialize(YAML::Node node) {
    bool success = Component::deserialize(node);
    fileName = node["fileName"].as<std::string>();
    width = node["width"].as<int>();
    height = node["height"].as<int>();

    return success;
}

void Image::render() {
    Component::render();

    if (image != NULL){
        SDL_Rect rect = {x:element->getTransform()->getPosition().x,y:element->getTransform()->getPosition().y,w:width,h:height};
        image->draw(rect);
    }
}
