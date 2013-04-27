#include <iostream>
#include <list>

#include "Entity.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

list<Entity*> entities;

//View view;

int main(int argc, char** argv) {
    RenderWindow window(VideoMode(640, 480), "minimalism");
    //View view(Vector2f(0, 0), Vector2f(320, 240));
    
    // initialize objects
    entities.push_back(new Player());
    
    while (window.IsOpened()) {
        Event event;

        while (window.GetEvent(event)) {
            if (event.Type == Event::Closed) {
                window.Close();
            }
        }

        for (auto itr = entities.begin(); itr != entities.end(); itr++) {
            if ((*itr)->removeme) {
                entities.erase(itr);
                delete *itr;
                continue;
            }
            
            (*itr)->step(window.GetFrameTime());

            if ((*itr)->removeme) {
                entities.erase(itr);
                delete *itr;
                continue;
            }
        }
        
        window.Clear();
	//window.SetView(view);

        for (auto itr = entities.begin(); itr != entities.end(); itr++) {
            (*itr)->draw(window);
        }
        
        window.Draw(Shape::Rectangle(Vector2f(0, 0), Vector2f(32, 32), Color(255, 0, 0)));

        window.Display();
    }
    return EXIT_SUCCESS;
}
