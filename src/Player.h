#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

#define PLAYER_MOVEMENT_SPEED 100
#define PLAYER_GRAVITY 600
#define PLAYER_TERMINAL_VELOCITY 512
#define PLAYER_JUMP_HEIGHT 400

class Player : public Entity {
public:
    Player(const sf::Vector2f pos);
    
    sf::Vector2f velocity;
    
    bool direction;
    bool jumping;
    bool grounded;
    
    virtual void create();
    virtual void step(float d);
    virtual void draw(sf::RenderTarget& target);
    virtual void event(sf::Event& event);
};
