#pragma once
#include "Entity.hpp"
#include "raylib.h"

class Person:
    public Entity
{
public:
    Person();
    ~Person();  
    // Orders to leave the room
    void leave();
    // Orders to enter the room
    void enter();
    void draw() override;
	bool isDisabled() { return disabled; }
protected:
	bool disabled;
};