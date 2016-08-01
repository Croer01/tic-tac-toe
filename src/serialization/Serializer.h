//
// Created by Adria on 30/07/2016.
//

#ifndef TIC_TAC_TOE_SERIALIZER_H
#define TIC_TAC_TOE_SERIALIZER_H


#include <string>
#include <map>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <cxxabi.h>
#include <typeindex>

namespace Serializer {

    template<typename T>
    class ObjectMetadataSerialize {
        std::string className;
    public:
        ObjectMetadataSerialize() {
            int status;
            className = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
        }

        inline std::string getClassName() const { return className; };

        T *createInstance() {
            return new T;
        }

    };

    template<typename T>
    ObjectMetadataSerialize<T> getMetadata() {
        return ObjectMetadataSerialize<T>();
    };

    template<typename T>
    void save(T *object) {
        std::string className = getMetadata<T>().getClassName();
        YAML::Node node;
        object->serialize(node[className]);

        std::ofstream fout(object->getName() + ".yaml");
        if (fout) {
            fout << node;
            if (fout) {
                fout.close();
            }
        }
    };

    template<typename T>
    static T *deserializeObject(YAML::Node node) {
        std::string className = node["className"].as<std::string>();

        T *objectDeserializet = getMetadata<T>().createInstance();
        objectDeserializet->deserialize(node);

        return objectDeserializet;
    };

    template<typename T>
    std::string getRealClassName(T object){
        int status;
        return abi::__cxa_demangle(std::type_index(typeid(object)).name(), 0, 0, &status);
    };
};

#endif //TIC_TAC_TOE_SERIALIZER_H
