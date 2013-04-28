#include "Entity.h"

using namespace sf;

Entity::Entity() : position(0, 0), dimensions(0, 0), removeme(false), handlesevents(false) {

}

bool Entity::isInGroup(Group group) {
    for (auto itr = collisionGroups.begin(); itr != collisionGroups.end(); itr++) {
        if (*itr == group) {
            return true;
        }
    }
    
    return false;
}

void Entity::addGroup(Group group) {
    if (!isInGroup(group)) {
        collisionGroups.push_back(group);
    }
}

void Entity::removeGroup(Group group) {
    collisionGroups.remove(group);
}

void Entity::create() {

}

void Entity::createFinalize() {
    created = true;
}

void Entity::event(Event &event) {
    
}


Vector2f Entity::intersect(Entity &other) {
    Vector2f amin, amax, bmin, bmax, encr, overlap;
    
    amin.x = position.x;
    amin.y = position.y;
    amax.x = position.x + dimensions.x;
    amax.y = position.y + dimensions.y;
    
    bmin.x = other.position.x;
    bmin.y = other.position.y;
    bmax.x = other.position.x + other.dimensions.x;
    bmax.y = other.position.y + other.dimensions.y;
    
    if (amin.x < bmax.x &&
        amin.y < bmax.y &&
        amax.x > bmin.x &&
        amax.y > bmin.y) {
        
        // intersecting, find least significant axis
        
        if (amax.y < bmax.y && amax.y >= bmin.y) {
            encr.y = bmin.y - amax.y;
        } else if (amin.y > bmin.y && amin.y <= bmax.y) {
            encr.y = bmax.y - amin.y;
        }
        
        if (amin.x < bmin.x && amax.x >= bmin.x) {
            encr.x = bmin.x - amax.x;
        } else if (amax.x > bmax.x && amin.x <= bmax.x) {
            encr.x = bmax.x - amin.x;
        }
        
        overlap.x = amin.x < bmin.x ? amax.x - bmin.x : bmax.x - amin.x;
        overlap.y = amin.y < bmin.y ? amax.y - bmin.y : bmax.y - amin.y;
        
        return Vector2f(overlap.x > overlap.y ? 0 : encr.x, overlap.y > overlap.x ? 0 : encr.y);
    } else {
        return Vector2f(0, 0);
    }
}
