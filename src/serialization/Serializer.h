//
// Created by Adria on 30/07/2016.
//

#ifndef TIC_TAC_TOE_SERIALIZER_H
#define TIC_TAC_TOE_SERIALIZER_H

#include <fstream>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include "Metadata.h"

class Scene;

class Serializer {
    Serializer() { };
    ~Serializer() { };
public:
    template<typename T>
    static std::string save(T *object, std::string fileName);

    template<typename T>
    static T *load(std::string filePath) {
        YAML::Node node = YAML::LoadFile(filePath);
        T *objectDeserializet = (T *) Metadata::deserialize(node);
        return objectDeserializet;
    };
};

#endif //TIC_TAC_TOE_SERIALIZER_H
