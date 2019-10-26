#pragma once

#include "Entity.hpp"
#include "raylib.h"

class Ghost:
    public Entity
{
public:
    Ghost();
    ~Ghost();
	virtual void draw();
};