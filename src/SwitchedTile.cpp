#include "SwitchedTile.h"
#include "util.h"

using namespace sf;

SwitchedTile::SwitchedTile(const sf::Vector2f &pos, int id) : Entity(pos), id(id) {
    dimensions.x = 64;
    dimensions.y = 64;
    
    addGroup(Group::Solid);
    addGroup(Group::Switchable);
}

void SwitchedTile::step(float d) {
    
}

void SwitchedTile::draw(sf::RenderTarget &target) {
    Color col(127, 0, 127);
    
    target.Draw(makeRectangle(position, dimensions, col));
}


int SwitchedTile::getSwitchId() {
    return id;
}

void SwitchedTile::enable() {
    remove();
}
