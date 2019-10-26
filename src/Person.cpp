#include "Person.hpp"
#include <iostream>

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

void Person::reactToInteraction(InteractionType type)
{
    switch (type) {
        case book:
            std::cout << "A book moved next to me!" << std::endl;
            break;

        case lampTurnOn:
            std::cout << "A lamp was turned on next to me!" << std::endl;
            break;

        case lampTurnOff:
            std::cout << "A lamp was turned off next to me!" << std::endl;
            break;

        default:
            break;
    }
}
