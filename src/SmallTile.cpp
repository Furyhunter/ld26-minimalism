#include "SmallTile.h"

SmallTile::SmallTile(const sf::Vector2f &pos): Tile(pos) {
    dimensions = sf::Vector2f(16, 16);
}