#include "Ghost.hpp"
#include "Constants.hpp"
#include <iostream>

Ghost::Ghost(float x, float y, Texture2D& ghostTexture) : 
	Entity(x, y, 16, 32),
	tileset(ghostTexture),
	spritesheet(16, 32, tileset.width, tileset.height)
{
	src = Rectangle{ 10 * 16, 16, 1 * 16, 2 * 16 };

	animationManager.addAnimation(0, { 1,2,3,4,5,6 }, 1 / 12.f, true);
	animationManager.addAnimation(1, { 13,14,15,16,17,18} , 1 / 12.f, true);
	animationManager.play(0, true);
}

Ghost::~Ghost()
{

}

void Ghost::draw()
{
    // Add movement so it looks like the ghost is floating
    float offset = GHOST_FLOAT_AMPLITUDE * (std::cos(GHOST_FLOAT_FREQUENCY * GetTime()) - 0.5);
    drawX = x;
    drawY = y + offset;

	int frameid = animationManager.getFrame();
	Rectangle _src = spritesheet.getSrcRect(frameid);
    DrawTexturePro(tileset, _src, Rectangle{ x, y + offset, SPRITES_SCALE * w, SPRITES_SCALE * h }, {}, 0.f, Color{255, 255, 255, GHOST_TRANSPARENCY});
}

void Ghost::update(float dt)
{
    updateAcceleration(dt);
    updateSpeed(dt);
    updateCooldown(dt);

    float dx = vx * dt;
    float dy = vy * dt;

	if (dy >= 0)
		animationManager.play(0, false);
	else
		animationManager.play(1, false);

    move(dx, dy);
	
	animationManager.update(dt);
}

float Ghost::getVx() {
    return vx;
}
float Ghost::getVy() {
    return vy;
}

void Ghost::clamp(float minX, float minY, float maxX, float maxY) {
    if (x < minX) {
        x = minX;
        vx = 0;
        ax = 0;
    } else if (x + w > maxX) {
        x = maxX - w;
        vx = 0;
        ax = 0;
    }

    if (y < minY) {
        y = minY;
        vy = 0;
        ay = 0;
    } else if (y + h > maxY) {
        y = maxY - h;
        vy = 0;
        ay = 0;
    }
}

void Ghost::moveTo(float x, float y) {
    this->x = x;
    this->y = y;
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

    // Make sure speed is not too small, or it's ugly on screen
    if (std::abs(vx) < 10) {
        vx = 0;
    }
    if (std::abs(vy) < 10) {
        vy = 0;
    }
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

float Ghost::getDrawX() {
    return drawX;
}

float Ghost::getDrawY() {
    return drawY;
}
