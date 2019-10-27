#pragma once

#include "Entity.hpp"
#include "raylib.h"
#include "GhostAction.hpp"
#include <cmath>
#include "AnimationManager.hpp"
#include "Spritesheet.hpp"

class Ghost:
    public Entity
{
public:
    Ghost(float x, float y, Texture2D& tileset);
    ~Ghost();

	virtual void draw();
    virtual void update(float dt);

    void setAcceleration(float angle, float amplitude);
    void doAction(GhostAction);

    float getVx();
    float getVy();
    
    void clamp(float minX, float minY, float maxX, float maxY);
    void moveTo(float x, float y);

private:
    float dashAx = 0;
    float dashAy = 0;
    float ax = 0;
    float ay = 0;
    float vx = 0;
    float vy = 0;

    float dashCooldown = 0;

	Texture2D& tileset;
	Rectangle src;

	Spritesheet spritesheet;
	AnimationManager animationManager;

    void updateAcceleration(float dt);
    void updateSpeed(float);
    void updateCooldown(float);

    void dash();
};
