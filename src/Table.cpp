#include "Table.hpp"

Table::Table() : Entity()
{

}

Table::~Table()
{

}

void Table::draw()
{
	DrawRectangle(x, y, 100, 50, BROWN);
}

Vector2 Table::getNextPosition()
{
	return Vector2{ 0.f, 0.f };
}