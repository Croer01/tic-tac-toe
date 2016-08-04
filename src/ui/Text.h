//
// Created by Adria on 18/06/2016.
//

#ifndef SDL_HELLO_WORLD_TEXT_H
#define SDL_HELLO_WORLD_TEXT_H


#include <string>
#include "UIElement.h"
#include "../core/Texture.h"

class Text : public UIElement {
    CREATE_METADATA(Text);

    std::string contentText;
    Texture *textToRender;
    bool textUpdated;

    void drawContentText();

public:
    Text(): UIElement(){};

    Text(SDL_Renderer *renderer, SDL_Rect bounds);

    void setText(std::string text);

    const std::string getText();

    virtual void render();

    virtual ~Text();

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


};


#endif //SDL_HELLO_WORLD_TEXT_H
