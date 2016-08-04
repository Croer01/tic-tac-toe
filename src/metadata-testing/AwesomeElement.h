//
// Created by Adria on 28/07/2016.
//

#ifndef TIC_TAC_TOE_AWESOMEELEMENT_H
#define TIC_TAC_TOE_AWESOMEELEMENT_H


#include "../core/game-objects/WorldElement.h"

class AwesomeElement : public WorldElement {
CREATE_METADATA(AwesomeElement);

public:

    AwesomeElement() : WorldElement() { }

    AwesomeElement(const std::string &name) : WorldElement(name) { }
};

#endif //TIC_TAC_TOE_AWESOMEELEMENT_H