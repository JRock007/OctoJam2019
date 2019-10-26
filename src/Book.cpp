#include "Book.hpp"

Book::Book(float x, float y) : 
	Entity(x, y, 20, 20)
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

void Book::draw()
{
	DrawRectangle(x, y, w, h, DARKGREEN);
}
