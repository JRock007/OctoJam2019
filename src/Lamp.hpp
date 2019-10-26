#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"

class Lamp:
    public Interactable,
    public Entity
{
public:
    Lamp(float x, float y, Table& table);
    ~Lamp();
    void interact();
    void toggle();
	bool isTurnedOn() { return turnedOn; }

protected:
    Table& table;
	bool turnedOn;
};