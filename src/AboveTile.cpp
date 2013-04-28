#include "AboveTile.h"

#include "Player.h"
#include "util.h"
#include "main.h"

using namespace sf;

AboveTile::AboveTile(const Vector2f& vec) : Entity(vec), player(nullptr) {
    dimensions = Vector2f(64, 64);
}

void AboveTile::step(float d) {
    if (player == nullptr) {
        player = static_cast<Player*>(getEntity([](Entity* arg) { return typeid(*arg) == typeid(Player); }));
    }
    
    if (player->position.y < position.y - player->dimensions.y && !isInGroup(Group::Solid)) {
        addGroup(Group::Solid);
    } else if (player->position.y > position.y && isInGroup(Group::Solid)) {
        removeGroup(Group::Solid);
    }
}

void AboveTile::draw(sf::RenderTarget &target) {
    Color mycolor(63, 63, 63);
    Shape sh = makeRectangle(position, dimensions, mycolor);
    
    target.Draw(sh);
}
