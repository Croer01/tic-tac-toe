//
// Created by Adria on 01/08/2016.
//

#ifndef TIC_TAC_TOE_REGISTERTOSERIALIZE_H
#define TIC_TAC_TOE_REGISTERTOSERIALIZE_H

#define YAML_SERIALIZER(className) \
namespace YAML {\
    template<>\
    struct convert<className> {\
        static Node encode(const className& rhs) {\
            Node node;\
            int status;\
            std::string name= abi::__cxa_demangle(std::type_index(typeid(rhs)).name(), 0, 0, &status);\
            rhs.serialize(node[name]);\
            return node;\
        }\
        static bool decode(const Node& node, className& rhs) {\
            return rhs.deserialize(node);\
        }\
    };\
};

#endif //TIC_TAC_TOE_REGISTERTOSERIALIZE_H
