#include "Player.h"

#include <iostream>
#include <list>
#include <cmath>

#include "main.h"
#include "util.h"

using namespace sf;
using namespace std;

Player::Player() : Player(Vector2f(32, 32)) {
    
}

Player::Player(const Vector2f pos) : Entity(), velocity(0, 0), direction(false), jumping(false), grounded(false) {
    dimensions = Vector2f(32, 32);
    
    position = pos;
    
    addGroup(Group::Player);
    
    handlesevents = true;
}

void Player::step(float d) {
    list<Entity*> ents;
    
    // apply gravity
    velocity.y += PLAYER_GRAVITY;
    
    if (direction) {
        velocity.x = PLAYER_MOVEMENT_SPEED;
    } else {
        velocity.x = -PLAYER_MOVEMENT_SPEED;
    }
    
    // collide with solids
    ents = getEntities([](Entity* ent) { return ent->isInGroup(Group::Solid); });
    
    for (auto itr = ents.begin(); itr != ents.end(); itr++) {
        Vector2f col(0, 0);
        
        col = intersect(**itr);
        position += col;
        
        if (col.x < 0) {
            direction = false;
        } else if (col.x > 0) {
            direction = true;
        }
        
        if (col.y < 0) { // floor
            jumping = false;
            grounded = true;
        }
        
        if (col.y != 0) {
            velocity.y = 0;
        }
    }
    
    if (abs(velocity.y) > 32) {
        grounded = false;
    }
    
    // apply velocity
    position += velocity * d;
}

void Player::draw(RenderTarget& target) {
    Color mycolor(140, 140, 220);
    
    target.Draw(makeRectangle(position, dimensions, mycolor));
}

void Player::event(Event& event) {
    if (event.Type == Event::KeyPressed) {
        if (event.Key.Code == Key::Z) {
            if (!jumping && grounded) {
                jumping = true;
                velocity.y -= PLAYER_JUMP_HEIGHT;
                position.y -= 1;
            }
        }
    }
    
    if (event.Type == Event::KeyReleased) {
        if (event.Key.Code == Key::Z) {
            if (jumping && velocity.y < 0) {
                jumping = false;
                velocity.y = -32;
            }
        }
    }
}