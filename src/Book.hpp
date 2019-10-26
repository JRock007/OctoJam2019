#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"

class Book:
    public Interactable,
    public Entity
{
public:
    Book(float x, float y);
    ~Book();
    void interact();
	void flip();
	virtual void draw() override;
protected:
};