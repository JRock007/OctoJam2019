#pragma once
#include "Entity.hpp"
#include "raylib.h"
#include "InteractionType.hpp"

class Person:
    public Entity
{
public:
    Person(float x, float y, Texture2D& tileset);
    ~Person();

    virtual void draw() override;
    void reactToInteraction(InteractionType);

    // Orders to leave the room
    void leave();
    // Orders to enter the room
    void enter();

    bool isDisabled() { return disabled; }

protected:
	bool disabled;
	Rectangle src;
	Texture2D& tileset;
};
