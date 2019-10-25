#include "Lamp.hpp"

Lamp::Lamp(Table table) : Entity()
{
    this->table = table
    turnedOn = true;
}

Lamp::~Lamp()
{

}

void Lamp::interact()
{
    toggle();
}

void toggle()
{
    turnedOn = !turnedOn;
}