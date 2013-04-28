#pragma once

#include <list>

#include <SFML/Graphics.hpp>

enum class Group : int {
    Solid = 0,
    Player,
    Switchable
};

class Entity {
public:
    Entity(const sf::Vector2f& pos);
    sf::Vector2f position;
    sf::Vector2f dimensions;
    bool removeme;
    bool handlesevents;
    bool created;

    virtual void create();
    void createFinalize();
    virtual void step(float delta) = 0;
    virtual void draw(sf::RenderTarget& target) = 0;
    virtual void event(sf::Event& event);
    void remove() { removeme = true; }
    
    sf::Vector2f intersect(Entity& other);
    
    bool isInGroup(Group group);
    void addGroup(Group group);
    void removeGroup(Group group);
private:
    std::list<Group> collisionGroups;
};
