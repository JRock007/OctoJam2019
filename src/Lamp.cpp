#include "Lamp.hpp"

Lamp::Lamp(float x, float y) : 
	Interactable(x, y, 10, 40),
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
	std::cout << "Lamp is:" << isHighlighted() << std::endl;

	if (isHighlighted())
		DrawRectangle(x - 3, y - 3, w + 6, h + 6, ORANGE);

	if (isTurnedOn())
		DrawRectangle(x, y, w, h, BLACK);
	else
		DrawRectangle(x, y, w, h, YELLOW);
}
