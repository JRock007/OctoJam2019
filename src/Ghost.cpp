#include "Ghost.hpp"
#include "Constants.hpp"
#include <iostream>

Ghost::Ghost() : Entity()
{
	w = 30;
	h = 40;
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

    float dX = vx * dt;
    float dY = vy * dt;
    x += dX;
    y += dY;
}

void Ghost::updateSpeed(float dt) {
    vx += (ax + dashAx) * dt;
    vy += (ay + dashAy) * dt;

    vx *= GHOST_FRICTION;
    vy *= GHOST_FRICTION;

    vx = std::fmin(vx, GHOST_MAX_SPEED);
    vx = std::fmax(vx, -GHOST_MAX_SPEED);

    vy = std::fmin(vy, GHOST_MAX_SPEED);
    vy = std::fmax(vy, -GHOST_MAX_SPEED);
}

void Ghost::updateAcceleration(float dt) {
    ax *= GHOST_FRICTION;
    ay *= GHOST_FRICTION;

    dashAx *= GHOST_FRICTION;
    dashAy *= GHOST_FRICTION;
}

void Ghost::setAcceleration(float angle, float amplitude) {
    ax = amplitude * std::cos(angle);
    ay = -amplitude * std::sin(angle);
}

void Ghost::doAction(GhostAction action) {
    switch (action) {
        case GhostAction::interact:
            std::cout << "Interact" << std::endl;
            break;

        case GhostAction::dash:
            dash();
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

void Ghost::dash() {
    std::cout << "Dash" << std::endl;

    if (ay == x && ay == 0) {
        // Don't dash if we're not moving
    } else {
        float angle = std::atan2(-ay, ax);
        dashAx = GHOST_DASH_ACCEL * std::cos(angle);
        dashAy = -GHOST_DASH_ACCEL * std::sin(angle);
    }
}
