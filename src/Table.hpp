#pragma once

#include "raylib.h"
#include "Entity.hpp"

class Table:
    public Entity
{
public:
    Table();
    ~Table();
    Vector2 getNextPosition();
};