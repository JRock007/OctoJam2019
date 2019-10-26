#include "Ghost.hpp"

Ghost::Ghost() : Entity()
{
	w = 30;
	h = 40;
}

Ghost::~Ghost()
{

}

void Ghost::draw()
{
	DrawRectangle(x, y, w, h, LIGHTGRAY);
}
