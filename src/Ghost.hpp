#pragma once

#include "Entity.hpp"
#include "raylib.h"
#include "GhostAction.hpp"
#include <cmath>

class Ghost:
    public Entity
{
public:
    Ghost();
    ~Ghost();

	virtual void draw();
    virtual void update(float dt);

    void setAcceleration(Vector2);
    void doAction(GhostAction);

private:
    Vector2 accel = Vector2{0.f, 0.f};
    Vector2 speed = Vector2{0.f, 0.f};

    void updateAcceleration(float dt);
    void updateSpeed(float);
};
