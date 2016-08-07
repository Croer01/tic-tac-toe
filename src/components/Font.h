//
// Created by Adria on 07/08/2016.
//

#ifndef TIC_TAC_TOE_FONT_H
#define TIC_TAC_TOE_FONT_H


#include <SDL_ttf.h>
#include "Component.h"

class Font : public Component {
CREATE_METADATA(Font);
    std::string fontFile;
    int size;
    TTF_Font *font;
public:
    ~Font();

    TTF_Font *getFont();

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);

};


#endif //TIC_TAC_TOE_FONT_H
