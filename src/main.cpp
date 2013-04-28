#include <iostream>
#include <list>

#include "main.h"

#include "Entity.h"
#include "Player.h"
#include "Tile.h"
#include "Camera.h"
#include "LevelLoader.h"
#include "BackgroundA.h"

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

list<Entity*> entities;

//View view;

int main(int argc, char** argv) {
    RenderWindow window(VideoMode(640, 480), "minimalism");
    
    // initialize objects
    entities.push_back(new BackgroundA());
    entities.push_back(new LevelLoader("data/level1.txt"));
    
    //window.UseVerticalSync(true);
    window.SetFramerateLimit(60);
    window.SetPosition((VideoMode::GetDesktopMode().Width/2)-320, (VideoMode::GetDesktopMode().Height/2)-240);
    
    while (window.IsOpened()) {
        Event event;
        float delta = window.GetFrameTime();

        while (window.GetEvent(event)) {
            if (event.Type == Event::Closed) {
                window.Close();
                clearEntities();
            }
            
            for (auto itr = entities.begin(); itr != entities.end(); itr++) {
                if ((*itr)->handlesevents) {
                    (*itr)->event(event);
                }
            }
        }

        for (auto itr = entities.begin(); itr != entities.end(); itr++) {
            if ((*itr)->removeme) {
                delete *itr;
                itr = entities.erase(itr);
                continue;
            }
            
            if (!(*itr)->created) {
                (*itr)->create();
                (*itr)->createFinalize();
            }
            
            (*itr)->step(delta);

            if ((*itr)->removeme) {
                delete *itr;
                itr = entities.erase(itr);
                continue;
            }
        }
        
        window.Clear();
        
        for (auto itr = entities.begin(); itr != entities.end(); itr++) {
            (*itr)->draw(window);
        }
        
        window.Display();
    }
    return EXIT_SUCCESS;
}

std::list< Entity * > getEntities(std::function< bool(Entity*) > predicate) {
    std::list<Entity*> ret;
    
    for (auto itr = entities.begin(); itr != entities.end(); itr++) {
        if (!(*itr)->removeme && predicate(*itr)) {
            ret.push_back(*itr);
        }
    }
    
    return ret;
}

Entity* getEntity(std::function< bool(Entity*) > predicate) {
    for (auto itr = entities.begin(); itr != entities.end(); itr++) {
        if (!(*itr)->removeme && predicate(*itr)) {
            return *itr;
        }
    }
    
    return nullptr;
}

void clearEntities(void) {
    entities.remove_if([](Entity* arg) { delete arg; return true; });
}
