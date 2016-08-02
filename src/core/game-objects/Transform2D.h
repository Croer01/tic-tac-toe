//
// Created by Adria on 27/07/2016.
//

#ifndef TIC_TAC_TOE_TRANSFORM2D_H
#define TIC_TAC_TOE_TRANSFORM2D_H


#include <SDL_rect.h>
#include "Component.h"


class Transform2D : public Component {
INSTANTIATOR(Transform2D);
private:
    SDL_Point position;
    SDL_Point scale;
    SDL_Point rotation;
public:
    Transform2D();

    //region getters_setters
    const SDL_Point &getPosition() const;

    void setPosition(const SDL_Point &position);

    const SDL_Point &getScale() const;

    void setScale(const SDL_Point &scale);

    const SDL_Point &getRotation() const;

    void setRotation(const SDL_Point &rotation);
    //endregion

    void move(const SDL_Point &movement);

    void rotate(const SDL_Point &rotation);

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


};

YAML_SERIALIZER(Transform2D);

#endif //TIC_TAC_TOE_TRANSFORM2D_H
