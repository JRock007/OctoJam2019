#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"
#include "Spritesheet.hpp"

class Lamp:
    public Interactable
{
public:
    Lamp(float x, float y, Texture2D& texture);
    ~Lamp();
	virtual void interact() override;
    void toggle();
	bool isTurnedOn() { return turnedOn; }
	virtual void draw() override;
protected:
	Texture2D& texture;
	Spritesheet spritesheet;
	bool turnedOn;
};