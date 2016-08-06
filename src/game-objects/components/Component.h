//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_COMPONENT_H
#define TIC_TAC_TOE_COMPONENT_H


#include <SDL_log.h>
#include <string>
#include "../../core/Object.h"
#include "../elements/Element.h"

class Component : public Object {
CREATE_METADATA(Component);
protected:
    Element* element;
public:
    Component();

    inline virtual void setName(std::string name) const{
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "can't change component %s name", this->name.c_str());
    }

    inline void setElement(Element *element){
        this->element = element;
    }

    virtual void init();

    virtual void update();

    virtual void render();
};

#endif //TIC_TAC_TOE_COMPONENT_H
