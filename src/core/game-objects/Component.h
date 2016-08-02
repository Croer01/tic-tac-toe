//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_COMPONENT_H
#define TIC_TAC_TOE_COMPONENT_H


#include <SDL_log.h>
#include <string>
#include "../Object.h"

class Component : public Object {
INSTANTIATOR(Component);
public:
    Component();

    inline virtual void setName(std::string name) const{
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "can't change component %s name", this->name.c_str());
    }
};

YAML_SERIALIZER(Component);


#endif //TIC_TAC_TOE_COMPONENT_H
