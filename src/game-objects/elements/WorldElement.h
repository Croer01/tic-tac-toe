//
// Created by Adria on 28/07/2016.
//

#ifndef TIC_TAC_TOE_WORLDELEMENT_H
#define TIC_TAC_TOE_WORLDELEMENT_H


#include "Element.h"
#include "../components/Transform2D.h"

class WorldElement : public Element{
CREATE_METADATA(WorldElement);
    Transform2D *transform;
public:

    WorldElement() : Element() {}

    WorldElement(const std::string &name);

    virtual bool deserialize(YAML::Node node);


};

#endif //TIC_TAC_TOE_WORLDELEMENT_H
