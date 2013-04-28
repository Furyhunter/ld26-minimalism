#include "LevelLoader.h"

#include <iostream>
#include <fstream>

#include "Tile.h"
#include "Player.h"
#include "main.h"
#include "Spring.h"
#include "Switch.h"
#include "SwitchedTile.h"
#include "SmallTile.h"
#include "AboveTile.h"
#include "NextLevel.h"
#include "EndGameGate.h"

using namespace std;
using namespace sf;

LevelLoader::LevelLoader(const char *path) : Entity(Vector2f(0, 0)), path(path) {
    
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
        
        if (type == "SmallTile") {
            file >> pos.x >> pos.y;
            entities.push_back(new SmallTile(pos));
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
        
        if (type == "Switch") {
            int id;
            
            file >> pos.x >> pos.y;
            file >> id;
            
            entities.push_back(new Switch(pos, id));
        }
        
        if (type == "SwitchedTile") {
            int id;
            
            file >> pos.x >> pos.y;
            file >> id;
            
            entities.push_back(new SwitchedTile(pos, id));
        }
        
        if (type == "AboveTile") {
            file >> pos.x >> pos.y;
            
            entities.push_back(new AboveTile(pos));
        }
        
        if (type == "NextLevel") {
            string meta;
            file >> pos.x >> pos.y;
            file >> meta;
            
            entities.push_back(new NextLevel(pos, meta.c_str()));
        }
        
        if (type == "EndGameGate") {
            file >> pos.x >> pos.y;
            
            entities.push_back(new EndGameGate(pos));
        }
    }
    
    file.close();
    remove();
}