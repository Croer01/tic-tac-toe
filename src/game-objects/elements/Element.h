//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_ELEMENT_H
#define TIC_TAC_TOE_ELEMENT_H


#include <vector>
#include "../../core/Object.h"

class Transform2D;
class Component;

class Element : public Object {

CREATE_METADATA(Element);
    std::vector<Component *> components;
    Transform2D *transform;
public:
    Element() :Object(){ };

    Element(std::string name);

    Component *getComponent(std::string componentName) const;

    void addComponent(Component *component);

    Transform2D * getTransform() const;

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);

    virtual void init();

    virtual void update();

    virtual void render();

};

#endif //TIC_TAC_TOE_ELEMENT_H
