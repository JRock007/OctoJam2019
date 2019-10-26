#include "Person.hpp"

Person::Person(float x, float y) : Entity(x, y, 10, 20)
{
    disabled = false;
}

Person::~Person()
{

}

void Person::leave()
{
    disabled = true;
}

void Person::enter()
{
    disabled = false;
}

void Person::draw()
{
	if (disabled) return;

    DrawRectangle(x, y, w, h, BLUE);
}