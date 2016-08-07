//
// Created by Adria on 18/06/2016.
//

#ifndef SDL_HELLO_WORLD_TEXT_H
#define SDL_HELLO_WORLD_TEXT_H


#include <string>
#include "../../core/Texture.h"
#include "../Component.h"
#include "../Font.h"

class Text : public Component {
CREATE_METADATA(Text);

    std::string contentText;
    Texture *textToRender;
    bool textUpdated;
    Font *fontComponent;

    void drawContentText();

public:
    Text();

    void setText(std::string text);

    const std::string getText();

    virtual void init();

    virtual void render();

    virtual ~Text();

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);

};


#endif //SDL_HELLO_WORLD_TEXT_H
