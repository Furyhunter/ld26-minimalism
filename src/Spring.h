#pragma once

#include "Entity.h"
#include "Direction.h"

class Spring : public Entity {
public:
    Spring();
    Spring(const sf::Vector2f& pos, Direction dir);
    
    Direction dir;
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
};