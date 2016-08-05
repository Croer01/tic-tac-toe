//
// Created by Adria on 02/08/2016.
//

#include "Metadata.h"


std::map<std::type_index, instantiator> Metadata::instantiatorsByType;
std::map<std::string, instantiator> Metadata::instantiatorsByString;


