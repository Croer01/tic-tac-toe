//
// Created by Adria on 04/08/2016.
//

#ifndef TIC_TAC_TOE_RESETBUTTON_H
#define TIC_TAC_TOE_RESETBUTTON_H


#include "Text.h"

class SaveSceneButton : public Text{
    CREATE_METADATA(SaveSceneButton);
public:
    SaveSceneButton() : Text(){};

    virtual void init(Game *game, SDL_Renderer *renderer);
};


#endif //TIC_TAC_TOE_RESETBUTTON_H
