//
// Created by Adria on 02/08/2016.
//

#include "Metadata.h"


std::map<std::type_index, Serializer::instantiator> Serializer::Metadata::instantiatorsByType;
std::map<std::string, Serializer::instantiator> Serializer::Metadata::instantiatorsByString;