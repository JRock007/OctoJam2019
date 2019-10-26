#pragma once

#include "raylib.h"
#include "Entity.hpp"

class Table:
    public Entity
{
public:
    Table();
    ~Table();
	void draw() override;
    Vector2 getNextPosition();
};