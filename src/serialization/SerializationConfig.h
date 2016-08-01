//
// Created by Adria on 01/08/2016.
//

#ifndef TIC_TAC_TOE_SERIALIZATIONCONFIG_H
#define TIC_TAC_TOE_SERIALIZATIONCONFIG_H

#include <SDL_rect.h>
#include <yaml-cpp/node/node.h>

namespace YAML {
    template<>
    struct convert<SDL_Point> {
        static Node encode(const SDL_Point& rhs) {
            Node node;
            node.push_back(rhs.x);
            node.push_back(rhs.y);
            return node;
        }

        static bool decode(const Node& node, SDL_Point& rhs) {
            if(!node.IsSequence() || node.size() != 2) {
                return false;
            }

            rhs.x = node[0].as<int>();
            rhs.y = node[1].as<int>();
            return true;
        }
    };
};

#endif //TIC_TAC_TOE_SERIALIZATIONCONFIG_H
