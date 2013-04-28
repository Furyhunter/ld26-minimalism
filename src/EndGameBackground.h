#pragma once

#include "Entity.h"

class EndGameBackground : public Entity {
public:
    EndGameBackground(const sf::Vector2f& pos);
    virtual void draw(sf::RenderTarget &target);
    virtual void step(float delta);
    
    float time;
    int state;
};