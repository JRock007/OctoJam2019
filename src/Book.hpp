#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"

class Book:
    public Interactable,
    public Entity
{
public:
    Book(Table table);
    ~Book();
    void interact();
    void flip();
    void drop();
protected:
    // The book is attached to a table
    Table table;
};