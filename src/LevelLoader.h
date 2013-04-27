#pragma once

#include <string>

#include "Entity.h"

class LevelLoader : public Entity {
public:
    LevelLoader(const char* path);
    
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
    
    std::string path;
};