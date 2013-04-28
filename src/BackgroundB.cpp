#include "BackgroundB.h"

#include "util.h"

using namespace sf;

BackgroundB::BackgroundB(): Entity(Vector2f(0, 0)), time(0), col(0, 0, 0) {

}

void BackgroundB::step(float delta) {
    time += delta;
    
    col.r = (127 * sin(time)) + 127;
    col.g = (127 * sin(time + 1)) + 127;
    col.b = (127 * sin(time + 2)) + 127;
}

void BackgroundB::draw(RenderTarget &target) {
    Shape sh(makeRectangle(target.GetView().GetCenter() - Vector2f(320, 240), Vector2f(640, 480), col));
    
    target.Draw(sh);
}
