//
// Created by Adria on 07/08/2016.
//

#include "Font.h"

INIT_METADATA(Font);

Font::~Font() {
    TTF_CloseFont(font);
    font=NULL;
}

TTF_Font *Font::getFont() {
    return font;
}

void Font::serialize(YAML::Node node) const {
    Component::serialize(node);

    node["fontFile"] = fontFile;
    node["size"] = size;
}

bool Font::deserialize(YAML::Node node) {
    bool success = Component::deserialize(node);
    fontFile = node["fontFile"].as<std::string>();
    size = node["size"].as<int>();
    font = TTF_OpenFont(fontFile.c_str(),size);
    return success;
}
