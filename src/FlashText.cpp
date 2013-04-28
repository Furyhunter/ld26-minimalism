#include "FlashText.h"

#include <cmath>

using namespace sf;
using namespace std;

Font font;
bool loaded = false;

FlashText::FlashText(const sf::Vector2f &pos, const char* text): Entity(pos), text(text), time(0), state(0) {
    
}

void FlashText::draw(sf::RenderTarget &target) {
    String string(text.c_str(), font);
    Color col(Color::Black);
    
    string.SetPosition(position);
    
    if (state == 0) {
        col.a = (int)roundf(time * 255);
    }
    if (state == 1) {
        col.a = 255;
    }
    if (state == 2) {
        col.a = (int)roundf((1-time) * 255);
    }
    string.SetColor(col);
    
    target.Draw(string);
}

void FlashText::step(float delta) {
    time += delta;
    
    if (!loaded) {
        loaded = font.LoadFromFile("data/DroidSans.ttf");
    }
    
    if (state == 0 && time > 1) {
        state = 1;
        time = 0;
    }
    
    if (state == 1 && time > 10) {
        state = 2;
        time = 0;
    }
    
    if (state == 2 && time > 1) {
        remove();
    }
}

