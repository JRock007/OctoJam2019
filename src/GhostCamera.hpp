#pragma once

#include "raylib.h"
#include "Ghost.hpp"
#include <cmath>

class GhostCamera {
public:
    GhostCamera(Ghost&);
    ~GhostCamera();

    void update(float dt);
    void jumpToPosition(float x, float y);

    float getX();
    float getY();

    Camera2D camera = {0};

private:
    float vx = 0;
    float vy = 0;

    Ghost& ghost;
    void updateSpeed();
};
