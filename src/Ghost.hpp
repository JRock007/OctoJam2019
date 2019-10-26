#pragma once

#include "Entity.hpp"
#include "raylib.h"

class Ghost:
    public Entity
{
public:
    Ghost(float x, float y);
    ~Ghost();
	virtual void draw();
};