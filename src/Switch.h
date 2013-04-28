#pragma once

#include "Entity.h"

class Switch : public Entity {
public:
    Switch(const sf::Vector2f& pos, int id);
    
    int id;
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
    void activate();
    bool activated;
};