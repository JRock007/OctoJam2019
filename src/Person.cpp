#include "Person.hpp"
#include <iostream>
#include <cstdlib>

Person::Person(float x, float y, Texture2D& tileset) :
	Entity(x, y, 16 * SPRITES_SCALE, 32 * SPRITES_SCALE),
	tileset(tileset),
	disabled(false)
{
	int id = std::rand() % 3;
	src = Rectangle{ (11.f + id) * 16, 16, 1 * 16, 2 * 16 };
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

    //DrawRectangle(x, y, w, h, BLUE);
	DrawTexturePro(tileset, src, Rectangle{ x,y,w,h }, {}, 0.f, WHITE);
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
