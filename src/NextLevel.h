#pragma once

#include <string>

#include "Entity.h"

class NextLevel : public Entity {
public:
    NextLevel(const sf::Vector2f &pos, const char *next);
    
    virtual void step(float delta);
    virtual void draw(sf::RenderTarget &target);
    
    float time;
    sf::Shape shape;
    std::string next;
};