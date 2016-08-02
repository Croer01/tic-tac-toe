//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_OBJECT_H
#define TIC_TAC_TOE_OBJECT_H

#include "../serialization/SerializerBase.h"
#include "../serialization/Register.h"
#include <yaml-cpp/yaml.h>

class Object {
INSTANTIATOR(Object);
protected:
    std::string name;
public:
    inline virtual std::string getName() const { return name; }

    inline virtual void setName(std::string name) { this->name = name; }

    virtual ~Object() { }

    virtual void serialize(YAML::Node node) const;
    virtual bool deserialize(YAML::Node node);
};

YAML_SERIALIZER(Object);



#endif //TIC_TAC_TOE_OBJECT_H
