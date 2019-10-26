#include "Person.hpp"

Person::Person() : Entity()
{
    disabled = false;
	w = 10;
	h = 20;
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