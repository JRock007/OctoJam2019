#pragma once

#include "Entity.hpp"
#include "raylib.h"
#include "GhostAction.hpp"
#include <cmath>

class Ghost:
    public Entity
{
public:
    Ghost(float x, float y);
    ~Ghost();

	virtual void draw();
    virtual void update(float dt);

    void setAcceleration(float angle, float amplitude);
    void doAction(GhostAction);

private:
    float dashAx = 0;
    float dashAy = 0;
    float ax = 0;
    float ay = 0;
    float vx = 0;
    float vy = 0;

    void updateAcceleration(float dt);
    void updateSpeed(float);

    void dash();
};
