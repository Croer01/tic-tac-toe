//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_ELEMENT_H
#define TIC_TAC_TOE_ELEMENT_H


#include <vector>
#include "Component.h"
#include "../Object.h"

class Element : public Object {
CREATE_METADATA(Element);
private:
    std::vector<Component *> components;
public:
    Element(){};
    Element(std::string name);

    Component *getComponent(std::string componentName);

    void addComponent(Component *component);

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


    void init();

    void update();

    void render();
};

#endif //TIC_TAC_TOE_ELEMENT_H
