#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"

class Book:
    public Interactable,
    public Entity
{
public:
    Book(float x, float y, Table& table);
    ~Book();
    void interact();
	void flip();
    void drop();
	virtual void draw() override;
protected:
    // The book is attached to a table
    Table& table;
};