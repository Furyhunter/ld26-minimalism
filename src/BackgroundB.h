#pragma once
#include "Entity.h"

class BackgroundB : public Entity {
public:
    BackgroundB();
    
    virtual void step(float delta); 
    virtual void draw(sf::RenderTarget &target);
    
    float time;
    sf::Color col;
};