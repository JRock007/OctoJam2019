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
    fadeTimer = PERSON_FADE_DURATION;
}

void Person::enter()
{
    disabled = false;
    fadeTimer = PERSON_FADE_DURATION;
}

void Person::draw()
{
    if (disabled && fadeTimer <= 0) {
        return;
    }

    unsigned char component = 255;

    if (fadeTimer > 0) {
        float advancement = fadeTimer / PERSON_FADE_DURATION;

        if (disabled) {
            // Fade-out
            component = advancement * 255;
        } else {
            // Fade-in
            component = (1 - advancement) * 255;
        }
    }

    auto drawColor = Color{component, component, component, component};
    DrawTexturePro(tileset, src, Rectangle{ x,y,w,h }, {}, 0.f, drawColor);
}

void Person::update(float dt) {
    if (fadeTimer > 0) {
        fadeTimer -= dt;
    }
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
