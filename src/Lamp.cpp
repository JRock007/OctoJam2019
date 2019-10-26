#include "Lamp.hpp"

Lamp::Lamp(Table& table) : 
	Entity(),
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