#pragma once

#include "raylib.h"
#include "Ghost.hpp"
#include "Window.hpp"
#include <cmath>

class GhostCamera {
public:
    GhostCamera(Ghost&, Window&);
    ~GhostCamera();

    void update(float dt);
    void jumpToPosition(float x, float y);

    float getX();
    float getY();

    void setBounds(float minX, float minY, float maxX, float maxY);

    Camera2D camera = {0};

private:
    float vx = 0;
    float vy = 0;
    float minX;
    float minY;
    float maxX;
    float maxY;

    Ghost& ghost;
    Window& window;
    void updateSpeed();
    void clamp();
};
