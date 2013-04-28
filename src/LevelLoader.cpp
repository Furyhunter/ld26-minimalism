#include "LevelLoader.h"

#include <iostream>
#include <fstream>

#include "Tile.h"
#include "Player.h"
#include "main.h"
#include "Spring.h"

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
        Vector2f pos;
        
        file >> type;
        
        if (type == "Tile") {
            file >> pos.x >> pos.y;
            entities.push_back(new Tile(pos));
        }
        
        if (type == "Player") {
            file >> pos.x >> pos.y;
            entities.push_back(new Player(pos));
        }
        
        if (type == "Spring") {
            Direction dir;
            int in;
            
            file >> pos.x >> pos.y;
            file >> in;
            
            switch (in) {
            case 0:
                dir = Direction::Up;
                break;
            case 1:
                dir = Direction::Down;
                break;
            case 2:
                dir = Direction::Left;
                break;
            case 3:
                dir = Direction::Right;
                break;
            }
            
            entities.push_back(new Spring(pos, dir));
        }
    }
    
    file.close();
    remove();
}