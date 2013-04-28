#include "Spring.h"
#include "util.h"

using namespace sf;

Spring::Spring(const Vector2f &pos, Direction dir) : Entity(pos), dir(dir) {
    switch (dir) {
    case Direction::Down:
    case Direction::Up:
        dimensions = Vector2f(32, 16);
        break;
    case Direction::Left:
    case Direction::Right:
        dimensions = Vector2f(16, 32);
        break;
    }
}

void Spring::step(float d) {
    
}

void Spring::draw(RenderTarget &target) {
    Color col(127, 127, 127);
    Color col2(60, 192, 60);
    switch (dir) {
    case Direction::Up:
        target.Draw(makeRectangle(position, Vector2f(32, 8), col2));
        target.Draw(makeRectangle(position + Vector2f(8, 8), Vector2f(16, 8), col));
        break;
    case Direction::Down:
        target.Draw(makeRectangle(position + Vector2f(0, 8), Vector2f(32, 8), col2));
        target.Draw(makeRectangle(position + Vector2f(8, 0), Vector2f(16, 8), col));
        break;
    case Direction::Left:
        target.Draw(makeRectangle(position, Vector2f(8, 32), col2));
        target.Draw(makeRectangle(position + Vector2f(8, 8), Vector2f(8, 16), col));
        break;
    case Direction::Right:
        target.Draw(makeRectangle(position + Vector2f(8, 0), Vector2f(8, 32), col2));
        target.Draw(makeRectangle(position + Vector2f(0, 8), Vector2f(8, 16), col));
        break;
    }
}