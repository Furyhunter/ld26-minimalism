#include "Camera.h"

using namespace sf;

Camera::Camera(Entity *target) : Entity(Vector2f(0, 0)), target(target), view() {
    view.SetHalfSize(Vector2f(320, 240));
    if (target != nullptr) {
        position = target->position;
    }
}

void Camera::step(float d) {
    Vector2f disp(0, 0);
    position.x = target->position.x;
    
    disp = target->position - position;
    
    position += (disp * .15f);
    
    view.SetCenter(Vector2f(320, position.y));
}

void Camera::draw(sf::RenderTarget &target) {
    target.SetView(view);
}

void Camera::event(sf::Event &event) {
    Entity::event(event);
}
