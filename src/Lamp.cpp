#include "Lamp.hpp"

Lamp::Lamp(float x, float y) : 
	Entity(x, y, 10, 40),
	turnedOn(true)
{

}

Lamp::~Lamp()
{

}

void Lamp::interact()
{
    toggle();
}

void Lamp::toggle()
{
    turnedOn = !turnedOn;
}

void Lamp::draw()
{
	DrawRectangle(x, y, w, h, YELLOW);
}
