#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"

class Book:
    public Interactable
{
public:
    Book(float x, float y);
    ~Book();
    void interact() override;
	void flip();
	virtual void draw() override;
};
