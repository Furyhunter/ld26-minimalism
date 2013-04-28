#include "Player.h"

#include <iostream>
#include <list>
#include <cmath>
#include <typeinfo>
#include <functional>

#include "main.h"
#include "util.h"
#include "Camera.h"
#include "Spring.h"

using namespace sf;
using namespace std;

Player::Player(const Vector2f pos) : Entity(), velocity(0, 0), direction(false), jumping(false), grounded(false) {
    dimensions = Vector2f(32, 32);
    
    position = pos;
    
    addGroup(Group::Player);
    
    handlesevents = true;
}

void Player::create() {
    Camera* cam;
    // make me a camera if there isn't one already
    
    cam = static_cast<Camera*> (getEntity([](Entity* arg) { return typeid(arg) == typeid(Camera); }));
    
    if (cam == nullptr) {
        cam = new Camera(this);
        entities.push_back(cam);
    }
}

void Player::step(float d) {
    list<Entity*> ents;
    
    // apply gravity
    velocity.y += PLAYER_GRAVITY * d;
    
    if (velocity.y > PLAYER_TERMINAL_VELOCITY) {
        velocity.y = PLAYER_TERMINAL_VELOCITY;
    }
    
    if (direction && velocity.x < PLAYER_MOVEMENT_SPEED) {
        velocity.x = PLAYER_MOVEMENT_SPEED;
    } else if (!direction && velocity.x > -PLAYER_MOVEMENT_SPEED) {
        velocity.x = -PLAYER_MOVEMENT_SPEED;
    }
    
    if (abs(velocity.x) > PLAYER_MOVEMENT_SPEED) {
        if (velocity.x > 0) velocity.x -= PLAYER_GRAVITY * d;
        if (velocity.x < 0) velocity.x += PLAYER_GRAVITY * d;
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
    
    // collide with springs
    ents = getEntities([](Entity* ent) { return typeid(*ent) == typeid(Spring); });
    
    for (auto itr = ents.begin(); itr != ents.end(); itr++) {
        Vector2f col(0, 0);
        col = intersect(**itr);
        
        if (col.x == 0 && col.y == 0) {
            // no collision
            continue;
        } else {
            Spring* spring = static_cast<Spring*>(*itr);
            switch (spring->dir) {
            case Direction::Up:
                velocity.y = -512;
                break;
            case Direction::Down:
                velocity.y = 512;
                break;
            case Direction::Left:
                velocity.x = -512;
                direction = false;
                break;
            case Direction::Right:
                velocity.x = 512;
                direction = true;
                break;
            }
        }
    }
    
    if (abs(velocity.y) > 32) {
        grounded = false;
    }
    
    // apply velocity
    position += velocity * d;
    
    // side collisions
    if (position.x > 640 - dimensions.x) {
        direction = false;
    }
    if (position.x < 0) {
        direction = true;
    }
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
                velocity.y = -PLAYER_JUMP_HEIGHT;
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