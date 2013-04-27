#include "LevelLoader.h"

#include <iostream>
#include <fstream>

#include "Tile.h"
#include "main.h"

using namespace std;
using namespace sf;

LevelLoader::LevelLoader(const char *path) : Entity(), path(path) {
    
}

void LevelLoader::draw(RenderTarget &target) {

}

void LevelLoader::step(float d) {
    ifstream file(path);
    
    if (!file.is_open()) {
        remove();
        return;
    }
    
    while (file.good()) {
        string type;
        
        file >> type;
        
        if (type == "Tile") {
            Vector2f pos;
            file >> pos.x >> pos.y;
            entities.push_back(new Tile(pos));
        }
        
        if (type == "Player") {
            Vector2f pos;
            file >> pos.x >> pos.y;
            entities.push_back(new Tile(pos));
        }
    }
    
    file.close();
    
    remove();
}