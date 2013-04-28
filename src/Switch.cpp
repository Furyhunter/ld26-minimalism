#include "Switch.h"

#include <list>
#include <iostream>

#include "ISwitchable.h"
#include "main.h"
#include "util.h"

using namespace sf;
using namespace std;

Switch::Switch(const Vector2f& pos, int id) : Entity(pos), activated(false), id(id) {
    dimensions = Vector2f(16, 16);
}

void Switch::step(float d) {
    
}

void Switch::draw(sf::RenderTarget &target) {
    Color col(0, 0, 0);
    
    if (activated) {
        col.r = 32;
        col.g = 200;
        col.b = 32;
    } else {
        col.r = 127;
        col.g = 31;
        col.b = 31;
    }
    
    target.Draw(makeRectangle(position, dimensions, col));
}

void Switch::activate() {
    list<Entity*> ents;
    
    if (activated) {
        return;
    }
    
    ents = getEntities([](Entity* arg) { return arg->isInGroup(Group::Switchable); });
    for (auto itr = ents.begin(); itr != ents.end(); itr++) {
        ISwitchable* s = dynamic_cast<ISwitchable*>(*itr);
        
        if (s->getSwitchId() == id) {
            s->enable();
            activated = true;
        }
    }
}