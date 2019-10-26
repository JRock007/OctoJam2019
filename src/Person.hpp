#pragma once
#include "Entity.hpp"
#include "raylib.h"

class Person:
    public Entity
{
public:
    Person(float x, float y);
    ~Person();  
    // Orders to leave the room
    void leave();
    // Orders to enter the room
    void enter();
    virtual void draw() override;
	bool isDisabled() { return disabled; }
protected:
	bool disabled;
};