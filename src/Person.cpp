#include "Person.hpp"
#include <iostream>
#include <cstdlib>

Person::Person(float x, float y, Texture2D& tileset, PersonOrientation orientation) :
	Entity(x, y, 16 * SPRITES_SCALE, 32 * SPRITES_SCALE),
	tileset(tileset),
    orientation(orientation)
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
    state = PersonState::leaving;
}

void Person::enter()
{
    disabled = false;
    fadeTimer = PERSON_FADE_DURATION;
    state = PersonState::entering;
}

void Person::draw()
{
    if (disabled && fadeTimer <= 0) {
        return;
    }

    auto drawColor = Color{255, 255, 255, 255};

    if (state == PersonState::leaving) {
        float advancement = fadeTimer / PERSON_FADE_DURATION;
        unsigned char component = advancement * 255;
        drawColor = Color{component, component, component, component};
    } else if (state == PersonState::entering) {
        float advancement = fadeTimer / PERSON_FADE_DURATION;
        unsigned char component = (1 - advancement) * 255;
        drawColor = Color{component, component, component, component};
    } else if (state == PersonState::excited) {
        drawColor = Color{255, 0, 0, 255};
    } else if (state == PersonState::scared) {
        drawColor = Color{0, 0, 255, 255};
    }

    DrawTexturePro(tileset, src, Rectangle{ x, y, w, h }, {}, 0.f, drawColor);
}

void Person::update(float dt) {
    if (fadeTimer > 0) {
        fadeTimer -= dt;

        if (fadeTimer <= 0) {
            state = disabled ? PersonState::disabled : PersonState::calm;
        }
    }

    if (state == PersonState::scared) {
        int limit = 1 / BECOME_CALM_PROBABILITY;
        float random = rand() % limit;

        if (random == (limit - 1)) {
            // Become calm
            state = PersonState::calm;
        }
    }

	animationManager.update(dt);
}

void Person::reactToInteraction(InteractionType type)
{
    switch (type) {
        case book:
        case lampTurnOn:
            case lampTurnOff:
            if (state == PersonState::excited) {
                state = PersonState::calm;
            } else if (state == PersonState::calm) {
                // Can become scared
                int limit = 1 / BECOME_SCARED_AFTER_INTERACTION_PROBABILITY;
                float random = rand() % limit;

                if (random == (limit - 1)) {
                    state = PersonState::scared;
                }
            } else if (state == PersonState::scared) {
                // Can leave if too scared
                int limit = 1 / LEAVE_AFTER_INTERACTION_PROBABILITY;
                float random = rand() % limit;

                if (random == (limit - 1)) {
                    leave();
                }
            }
            break;

        default:
            break;
    }
}

PersonState Person::getState() {
    return state;
}

void Person::becomeExcited() {
    if (state == PersonState::calm) {
        state = PersonState::excited;
    }
}
