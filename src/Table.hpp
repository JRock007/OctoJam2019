#pragma once

#include "raylib.h"
#include "Entity.hpp"

class Table:
    public Entity
{
    Table();
    ~Table();
    Vector2 getNextPosition();
};