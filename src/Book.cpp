#include "Book.hpp"

Book::Book(float x, float y, Table& table) : 
	Entity(x, y, 20, 20),
	table(table)
{
}

Book::~Book()
{

}

void Book::interact()
{

}

void Book::flip()
{

}

void Book::drop()
{

}

void Book::draw()
{
	DrawRectangle(x, y, w, h, DARKGREEN);
}
