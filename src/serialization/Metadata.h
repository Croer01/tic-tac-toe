//
// Created by Adria on 02/08/2016.
//

#ifndef TIC_TAC_TOE_METADATA_H
#define TIC_TAC_TOE_METADATA_H

#include <string>
#include <typeindex>
#include <cxxabi.h>
#include <map>
#include <yaml-cpp/yaml.h>

class Object;

typedef Object *(*instantiator)(YAML::Node);

class Metadata {
protected:
    static std::map<std::type_index, instantiator> instantiatorsByType;
    static std::map<std::string, instantiator> instantiatorsByString;
public:
    template<typename T>
    static void registerInstantiator() {
        int status;
        std::type_index typeIndex = std::type_index(typeid(T));
        std::string className = abi::__cxa_demangle(typeIndex.name(), 0, 0, &status);
        instantiator newInstance = [](YAML::Node node) {
            T *object = new T();
            object->deserialize(node);
            return (Object *) object;
        };

        instantiatorsByType[typeIndex] = newInstance;
        instantiatorsByString[className] = newInstance;
    }

    static Object *deserialize(YAML::Node node) {
        std::string className = node["className"].as<std::string>();
        return instantiatorsByString[className](node);
    }

    template<typename T>
    static YAML::Node serialize(T *object) {
        int status;
        YAML::Node node;
        node["className"] = abi::__cxa_demangle(std::type_index(typeid(*object)).name(), 0, 0, &status);
        object->serialize(node);
        return node;
    }
};

#endif //TIC_TAC_TOE_METADATA_H
