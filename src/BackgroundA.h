#pragma once
#include "Entity.h"

class BackgroundA : public Entity {
public:
    BackgroundA();
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
    
    sf::Color colA;
    sf::Color colB;
    float time;
};