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
    updateCooldown(dt);

    float dx = vx * dt;
    float dy = vy * dt;
    move(dx, dy);
}

float Ghost::getVx() {
    return vx;
}
float Ghost::getVy() {
    return vy;
}

void Ghost::setAcceleration(float angle, float amplitude) {
    ax = amplitude * std::cos(angle);
    ay = -amplitude * std::sin(angle);
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

void Ghost::updateCooldown(float dt) {
    if (dashCooldown > 0) {
        dashCooldown -= dt;
    }
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
    if (std::abs(vx) < GHOST_MIN_SPEED_FOR_DASH && std::abs(vy) < GHOST_MIN_SPEED_FOR_DASH) {
        // Don't dash if we're not moving
    } else if (dashCooldown > 0) {
        // Cooldown isn't over yet
    } else {
        float angle = std::atan2(-vy, vx);
        dashAx = GHOST_DASH_ACCEL * std::cos(angle);
        dashAy = -GHOST_DASH_ACCEL * std::sin(angle);
        dashCooldown = GHOST_DASH_COOLDOWN;
    }
}
