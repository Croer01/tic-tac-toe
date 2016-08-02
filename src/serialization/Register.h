//
// Created by Adria on 02/08/2016.
//

#ifndef TIC_TAC_TOE_REGISTER_H
#define TIC_TAC_TOE_REGISTER_H


#include "Metadata.h"

namespace Serializer {
    template<typename T>
    class Register {
    public:
        Register() {
            Serializer::Metadata::registerInstantiator<T>();
        }
    };
};

#endif //TIC_TAC_TOE_REGISTER_H
