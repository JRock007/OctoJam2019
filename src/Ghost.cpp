#include "Ghost.hpp"
#include "Constants.hpp"
#include <iostream>

Ghost::Ghost(float x, float y) : Entity(x, y, 30, 40)
{
}

Ghost::~Ghost()
{

}

void Ghost::draw()
{
	DrawRectangle(x, y, w, h, LIGHTGRAY);
}

void Ghost::update(float dt)
{
    updateAcceleration(dt);
    updateSpeed(dt);

    float dX = speed.x * dt;
    float dY = speed.y * dt;
    x += dX;
    y += dY;
}

void Ghost::updateSpeed(float dt) {
    speed.x += accel.x * dt;
    speed.y += accel.y * dt;

    speed.x *= GHOST_FRICTION;
    speed.y *= GHOST_FRICTION;

    speed.x = std::fmin(speed.x, GHOST_MAX_SPEED);
    speed.x = std::fmax(speed.x, -GHOST_MAX_SPEED);

    speed.y = std::fmin(speed.y, GHOST_MAX_SPEED);
    speed.y = std::fmax(speed.y, -GHOST_MAX_SPEED);
}

void Ghost::updateAcceleration(float dt) {
    accel.x *= GHOST_FRICTION;
    accel.y *= GHOST_FRICTION;
}

void Ghost::setAcceleration(Vector2 accel) {
    this->accel = accel;
}

void Ghost::doAction(GhostAction action) {
    switch (action) {
        case GhostAction::interact:
            std::cout << "Interact" << std::endl;
            break;

        case GhostAction::dash:
            std::cout << "Dash" << std::endl;
            break;
        
        case GhostAction::shush:
            std::cout << "Shush" << std::endl;
            break;

        case GhostAction::fusrodah:
            std::cout << "FusRoDah" << std::endl;
            break;
            
        case GhostAction::none:
            break;
    }
}
