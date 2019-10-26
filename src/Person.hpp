#pragma once
#include "Entity.hpp"

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
	bool isDisabled() { return disabled; }
protected:
	bool disabled;
};