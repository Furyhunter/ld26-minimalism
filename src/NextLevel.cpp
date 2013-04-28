#include "NextLevel.h"

#include "Player.h"
#include "main.h"
#include "LevelLoader.h"

using namespace sf;

NextLevel::NextLevel(const sf::Vector2f &pos, const char* next) : Entity(pos), time(0), shape(Shape::Circle(Vector2f(0, 0), 16, Color(31, 31, 191))), next(next) {
    
}

void NextLevel::step(float delta) {
    Player* player = static_cast<Player*>(getEntity([](Entity* arg) { return typeid(*arg) == typeid(Player); }));
    
    time += delta;
    
    if (time > 1) {
        
    }
    
    // collide with player
    if (player != nullptr) {
        Vector2f cos(intersect(*player));
        
        if (cos.x != 0 || cos.y != 0) {
            getEntities([](Entity* arg) { arg->remove(); return false; });
            entities.push_back(new LevelLoader(next.c_str()));
        }
    }
}

void NextLevel::draw(sf::RenderTarget &target) {
    shape.SetPosition(position);
    
    target.Draw(shape);
}
