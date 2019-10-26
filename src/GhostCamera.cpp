#include "GhostCamera.hpp"
#include "Constants.hpp"

GhostCamera::GhostCamera(Ghost& ghost, Window& window) :
    ghost(ghost),
    window(window),
    minX(0),
    minY(0),
    maxX(window.getWidth()),
    maxY(window.getHeight())
{
    camera.offset = Vector2{static_cast<float>(GetScreenWidth() / 2),
                            static_cast<float>(GetScreenHeight() / 2)};
    camera.target = Vector2{0, 0};
    camera.rotation = 0;
    camera.zoom = 1;
}

GhostCamera::~GhostCamera() {}

void GhostCamera::update(float dt) {
    updateSpeed();

    // Update camera position
    camera.target.x += vx * dt;
    camera.target.y += vy * dt;

    // Ensure the camera doesn't go out of bounds
    clamp();
}

void GhostCamera::jumpToPosition(float x, float y) {
    camera.target.x = x;
    camera.target.y = y;
}

void GhostCamera::setBounds(float minX, float minY, float maxX, float maxY) {
    this->minX = minX;
    this->maxX = maxX;
    this->minY = minY;
    this->maxY = maxY;
}

float GhostCamera::getX() {
    return camera.target.x;
}

float GhostCamera::getY() {
    return camera.target.y;
}

void GhostCamera::updateSpeed() {
    vx = CAMERA_SLOW_RATIO * ghost.getVx();
    vy = CAMERA_SLOW_RATIO * ghost.getVy();

    // Add speed based on distance
    vx += CAMERA_CATCHUP_RATIO * (ghost.getX() - camera.target.x);
    vy += CAMERA_CATCHUP_RATIO * (ghost.getY() - camera.target.y);
}

void GhostCamera::clamp() {
    if (camera.target.x - camera.offset.x < minX) {
        camera.target.x = minX + camera.offset.x;
    } else if (camera.target.x + camera.offset.x > maxX) {
        camera.target.x = maxX - camera.offset.x;
    }

    if (camera.target.y - camera.offset.y < minY) {
        camera.target.y = minY + camera.offset.y;
    } else if (camera.target.y + camera.offset.y > maxY) {
        camera.target.y = maxY - camera.offset.y;
    }
}
