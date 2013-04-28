#pragma once

#include "Entity.h"
#include "ISwitchable.h"

class SwitchedTile : public Entity, public ISwitchable {
public:
    SwitchedTile(const sf::Vector2f& pos, int id);
    
    int id;
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget &target);
    
    void enable();
    int getSwitchId();
};