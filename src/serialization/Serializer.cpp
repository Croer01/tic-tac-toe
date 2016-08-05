//
// Created by Adria on 02/08/2016.
//

#include "Serializer.h"
#include "../core/Scene.h"

template<typename T>
std::string saveObject(T *object, std::string fileName) {
    YAML::Node node = Metadata::serialize(object);
    std::ofstream fout(fileName);
    if (fout) {
        fout << node;
        if (fout) {
            fout.close();
            return fileName;
        }
    }

    return "";
}

template<typename T>
std::string Serializer::save(T *object, std::string fileName) {
    return saveObject(object, fileName + ".yaml");
}

template<>
std::string Serializer::save<Scene>(Scene *object, std::string fileName) {
    return saveObject(object, fileName + ".scene");
}
