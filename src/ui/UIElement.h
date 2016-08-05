//
// Created by Adria on 18/06/2016.
//

#ifndef SDL_HELLO_WORLD_UIELEMENT_H
#define SDL_HELLO_WORLD_UIELEMENT_H


#include <SDL_rect.h>
#include <SDL_render.h>
#include <functional>
#include "../game-objects/elements/Element.h"
#include "../game-objects/components/Transform2D.h"

class UIElement : public Element{
CREATE_METADATA(UIElement);
protected:
    Transform2D *transform;

    std::function<void()> onClickCallback;

    void clickEvent();

public:
    UIElement(): Element(){};
    UIElement(SDL_Renderer *renderer, SDL_Rect bounds);

    void addOnClickHandler(std::function<void()> handler);

    virtual void update();

    virtual void serialize(YAML::Node node) const;

    virtual bool deserialize(YAML::Node node);


};


#endif //SDL_HELLO_WORLD_UIELEMENT_H
