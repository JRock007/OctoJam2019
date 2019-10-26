#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"

class Lamp:
    public Interactable,
    public Entity
{
public:
    Lamp(Table table);
    ~Lamp();
    void interact();
    void toggle();
    bool isTurnedOn() { return turnedOn; }
protected:
    Table table;
    bool turnedOn;
};