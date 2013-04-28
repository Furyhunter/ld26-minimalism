#include "BackgroundA.h"

#include <cmath>

#include "util.h"

using namespace std;
using namespace sf;

BackgroundA::BackgroundA() : Entity(), colA(64, 64, 64), colB(64, 64, 64), time(0) {

}

void BackgroundA::draw(sf::RenderTarget &target) {
    int x, y;
    bool alternate = false;
    Vector2f offset;
    Shape rect;
    
    offset = target.GetView().GetCenter();
    offset.y *= .80f;
    
    rect = makeRectangle(Vector2f(0, 0), Vector2f(12, 12), Color::White);
    
    for (x = -320; x < 320; x += 30) {
        for (y = -240; y < 990; y += 30) {
            rect.SetPosition(offset + Vector2f(x, y));
            rect.SetColor(alternate ? colA : colB);
            target.Draw(rect);
            alternate = alternate ? false : true;
        }
    }
}

void BackgroundA::step(float d) {
    time += d;
    
    colA.r = (1 + sin(time)) * 32 + 32;
    colA.g = (1 + sin(time)) * 32 + 32;
    colA.b = (1 + sin(time)) * 32 + 32;
    
    colB.r = (1 + cos(time)) * 32 + 32;
    colB.g = (1 + cos(time)) * 32 + 32;
    colB.b = (1 + cos(time)) * 32 + 32;
}
