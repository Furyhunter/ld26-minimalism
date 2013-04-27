#pragma once

#include <list>
#include <functional>

#include "Entity.h"

//extern View view;
extern std::list<Entity*> entities;

std::list<Entity*> getEntities(std::function<bool(Entity*)> predicate);
Entity* getEntity(std::function<bool(Entity*)> predicate);
void clearEntities(void);