//
// Created by Adria on 28/07/2016.
//

#ifndef TIC_TAC_TOE_WORLDELEMENT_H
#define TIC_TAC_TOE_WORLDELEMENT_H


#include "Element.h"

class WorldElement : public Element{
public:
    WorldElement(const std::string &name);
};

YAML_SERIALIZER(WorldElement);

#endif //TIC_TAC_TOE_WORLDELEMENT_H
