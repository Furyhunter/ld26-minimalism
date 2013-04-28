#pragma once

#include "Entity.h"

class Player;

class AboveTile : public Entity {
public:
    AboveTile(const sf::Vector2f& vec);
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
    
    Player* player;
};