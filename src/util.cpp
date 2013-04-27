#include "util.h"

sf::Shape makeRectangle(sf::Vector2f pos, sf::Vector2f dim, sf::Color color) {
    return sf::Shape::Rectangle(pos, pos + dim, color);
}