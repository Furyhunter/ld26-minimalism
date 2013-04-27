#include "Player.h"

using namespace sf;

Player::Player() : Entity() {
    
}

void Player::step(float d) {
    
}

void Player::draw(RenderTarget& target) {
    target.Draw(Shape::Rectangle(position, dimensions, Color(255, 0, 0)));
}
