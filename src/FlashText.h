#pragma once

#include <string>

#include "Entity.h"

class FlashText : public Entity {
public:
    FlashText(const sf::Vector2f &pos, const char *text);
    virtual void draw(sf::RenderTarget &target);
    virtual void step(float delta);
    
    std::string text;
    float time;
    int state;
};