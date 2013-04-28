#include "Tile.h"

#include "util.h"

using namespace sf;

Tile::Tile(Vector2f vec) : Entity(vec) {
    dimensions = Vector2f(64, 64);
    
    position = vec;
    
    addGroup(Group::Solid);
}

void Tile::step(float d) {

}


void Tile::draw(sf::RenderTarget &target) {
    Color mycolor(127, 127, 127);
    
    target.Draw(makeRectangle(position, dimensions, mycolor));
}
