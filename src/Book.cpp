#include "Book.hpp"

Book::Book(float x, float y) : 
	Interactable(x, y, 20, 20)
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
	if (isHighlighted())
		DrawRectangle(x - 3, y - 3, w + 6, h + 6, GREEN);

	DrawRectangle(x, y, w, h, DARKGREEN);
}
