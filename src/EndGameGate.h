#pragma once

#include "Entity.h"

class EndGameGate : public Entity {
public:
    EndGameGate(const sf::Vector2f& pos);
    
    virtual void step(float delta);
    virtual void draw(sf::RenderTarget &target);
};
