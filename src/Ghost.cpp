#include "Ghost.hpp"

Ghost::Ghost(float x, float y) : Entity(x, y, 30, 40)
{
}

Ghost::~Ghost()
{

}

void Ghost::draw()
{
	DrawRectangle(x, y, w, h, LIGHTGRAY);
}
