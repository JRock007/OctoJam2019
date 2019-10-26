#include "Lamp.hpp"

Lamp::Lamp(float x, float y, Table& table) : 
	Entity(x, y, 10, 40),
	table(table),
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