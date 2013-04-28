#include "EndGameBackground.h"
#include "util.h"
#include "main.h"

#include "FlashText.h"

using namespace sf;

EndGameBackground::EndGameBackground(const sf::Vector2f &pos): Entity(pos), time(0), state(0) {
    
}

void EndGameBackground::draw(sf::RenderTarget &target) {
    Shape sh;
    target.SetView(target.GetDefaultView());
    sh = makeRectangle(Vector2f(0, 0), Vector2f(640, 480), Color::White);
    target.Draw(sh);
}

void EndGameBackground::step(float delta) {
    time += delta;
    
    if (time > 2 && state == 0) {
        state = 1;
        time = 0;
        
        entities.push_back(new FlashText(Vector2f(32, 32), "You've reached the top"));
    }
    
    if (time > 2 && state == 1) {
        state = 2;
        time = 0;
        
        entities.push_back(new FlashText(Vector2f(32, 64), "And now you're free."));
    }
    
    if (time > 2 && state == 2) {
        state = 3;
        time = 0;
        
        entities.push_back(new FlashText(Vector2f(32, 96), "Thank you for what"));
    }
    
    if (time > 2 && state == 3) {
        state = 4;
        time = 0;
        
        entities.push_back(new FlashText(Vector2f(32, 128), "you've done for me."));
    }
    
    if (time > 2 && state == 4) {
        state = 5;
        time = 0;
        
        entities.push_back(new FlashText(Vector2f(90, 350), "In loving memory of Lance and Chrystal."));
    }
}

