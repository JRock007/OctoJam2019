#include "Table.hpp"

Table::Table() : Entity()
{
	w = 100;
	h = 50;
}

Table::~Table()
{

}

void Table::draw()
{
	DrawRectangle(x, y, w, h, BROWN);
}

Vector2 Table::getNextPosition()
{
	bool prim = std::rand() % 2;
	bool secd = std::rand() % 2;
	Vector2 nextPosition {};

	// Horizontal or Vertical
	if (prim)
	{
		int nextx = x + std::rand() % (int)w;
		int nexty = y + (secd) ? 0 : h;
		nextPosition = Vector2{ x, y };
	}
	else
	{
		// Left or Right
		int nextx = x + (secd) ? 0 : w;
		int nexty = y + std::rand() % (int)h;
		nextPosition = Vector2{ x, y };
	}

	return nextPosition;
}