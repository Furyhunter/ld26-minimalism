#include "EndGameGate.h"

#include "Player.h"
#include "main.h"
#include "util.h"
#include "EndGameBackground.h"

using namespace sf;

EndGameGate::EndGameGate(const sf::Vector2f &pos): Entity(pos) {
    dimensions = Vector2f(32, 32);
}

void EndGameGate::step(float delta) {
    Player* player = nullptr;
    // test collision with player
    
    player = static_cast<Player*>(getEntity([](Entity* arg) { return typeid(*arg) == typeid(Player); }));
    
    if (player != nullptr) {
        Vector2f cos;
        
        cos = intersect(*player);
        
        if (cos.x != 0 || cos.y != 0) {
            getEntities([this](Entity* arg) {
                if (arg != this) {
                    arg->remove();
                }
                return false;
            });
            remove();
            entities.push_back(new EndGameBackground(Vector2f(0, 0)));
            return;
        }
    }
}

void EndGameGate::draw(RenderTarget &target) {
    Color col(191, 191, 63);
    Shape sh(makeRectangle(position, dimensions, col));
    
    target.Draw(sh);
}
