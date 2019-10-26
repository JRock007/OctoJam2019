#include "GhostCamera.hpp"
#include "Constants.hpp"

GhostCamera::GhostCamera(Ghost& ghost) : ghost(ghost) {
    camera.offset = Vector2{static_cast<float>(GetScreenWidth() / 2),
                            static_cast<float>(GetScreenHeight() / 2)};
    camera.target = Vector2{0, 0};
    camera.rotation = 0;
    camera.zoom = 1;
}

GhostCamera::~GhostCamera() {}

void GhostCamera::update(float dt) {
    updateSpeed();
    camera.target.x += vx * dt;
    camera.target.y += vy * dt;
}

void GhostCamera::jumpToPosition(float x, float y) {
    camera.target.x = x;
    camera.target.y = y;
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
