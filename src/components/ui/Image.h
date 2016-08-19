//
// Created by Adria on 08/08/2016.
//

#ifndef TIC_TAC_TOE_IMAGE_H
#define TIC_TAC_TOE_IMAGE_H


#include <SDL_render.h>
#include "../Component.h"
#include "../../core/Texture.h"

class Image : public Component {
CREATE_METADATA(Image);
    Texture *image;
    int width;
    int height;
    std::string fileName;

public:
    Image();

    ~Image();

    int getImageWidth();

    int getImageHeight();

    virtual void init();

    virtual void render();

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


};


#endif //TIC_TAC_TOE_IMAGE_H
