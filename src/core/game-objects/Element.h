//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_ELEMENT_H
#define TIC_TAC_TOE_ELEMENT_H


#include <vector>
#include "Component.h"
#include "../Object.h"

class Element : public Object {
private:
    std::vector<Component *> components;
public:
    Element(std::string name);

    Component *getComponent(std::string name);

    void addComponent(Component *component);

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


};

YAML_SERIALIZER(Element);

#endif //TIC_TAC_TOE_ELEMENT_H
