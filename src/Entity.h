#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity();
    sf::Vector2f position;
    sf::Vector2f dimensions;
    bool removeme;

    virtual void step(float delta) = 0;
    virtual void draw(sf::RenderTarget& target) = 0;
    void remove() { removeme = true; }
};
