#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"

class Lamp:
    public Interactable,
    public Entity
{
public:
    Lamp(float x, float y);
    ~Lamp();
	virtual void interact() override;
    void toggle();
	bool isTurnedOn() { return turnedOn; }
	virtual void draw() override;
protected:
	bool turnedOn;
};