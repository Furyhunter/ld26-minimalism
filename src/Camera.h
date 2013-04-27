#pragma once

#include "Entity.h"

class Camera : public Entity {
public:
    Camera(Entity* target);
    
    sf::View view;
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
    virtual void event(sf::Event& event);
    
    Entity* target;
};