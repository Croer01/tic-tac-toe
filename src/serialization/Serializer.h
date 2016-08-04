//
// Created by Adria on 30/07/2016.
//

#ifndef TIC_TAC_TOE_SERIALIZER_H
#define TIC_TAC_TOE_SERIALIZER_H

#include <fstream>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include "Metadata.h"

namespace Serializer {
    template<typename T>
    void save(T *object, std::string fileName) {
        YAML::Node node = Metadata::serialize(object);
        std::ofstream fout(fileName + ".yaml");
        if (fout) {
            fout << node;
            if (fout) {
                fout.close();
            }
        }
    };


    template<typename T>
    T *load(std::string filePath) {
        YAML::Node node = YAML::LoadFile(filePath);
        T *objectDeserializet = (T*) Metadata::deserialize(node);
        return objectDeserializet;
    };
};

#endif //TIC_TAC_TOE_SERIALIZER_H
