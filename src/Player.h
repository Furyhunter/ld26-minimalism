#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Player : public Entity {
public:
    Player();
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
};
