#pragma once

#include "Entity.h"

class Tile : public Entity {
public:
    Tile(sf::Vector2f vec);
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
};