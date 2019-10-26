#pragma once

#include "raylib.h"
#include "Entity.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

class Table:
    public Entity
{
public:
    Table(float x, float y, Texture2D& texture, Rectangle src);
    ~Table();
	void draw() override;
    Vector2 getNextPosition();
private:
	Texture2D& texture;
	Rectangle src;
};