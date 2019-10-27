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

    // Make sure speed is not too small, or it's ugly on screen
    if (std::abs(vx) < 10) {
        vx = 0;
    }
    if (std::abs(vy) < 10) {
        vy = 0;
    }
}

void GhostCamera::clamp() {
    float offsetX = camera.offset.x / camera.zoom;
    float offsetY = camera.offset.y / camera.zoom;

    if (camera.target.x - offsetX < minX) {
        camera.target.x = minX + offsetX;
    } else if (camera.target.x + offsetX > maxX) {
        camera.target.x = maxX - offsetX;
    }

    if (camera.target.y - offsetY < minY) {
        camera.target.y = minY + offsetY;
    } else if (camera.target.y + offsetY > maxY) {
        camera.target.y = maxY - offsetY;
    }
}
