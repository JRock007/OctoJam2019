#include "Table.hpp"

Table::Table(float x, float y, Texture2D& texture, Rectangle src) : 
	Entity(x, y, src.width, src.height),
	texture(texture),
	src(src)
{

}

Table::~Table()
{

}

void Table::draw()
{
	Rectangle dst = { x, y, SPRITES_SCALE * src.width, SPRITES_SCALE * src.height };
	DrawTexturePro(texture, src, dst, Vector2{}, 0.f, WHITE);
}

Vector2 Table::getNextPosition()
{
	bool prim = std::rand() % 2;
	bool secd = std::rand() % 2;
	Vector2 nextPosition {};

	// Horizontal or Vertical
	if (prim)
	{
		float nextx = x + std::rand() % (int)w;
		float nexty = y + ((secd) ? 0 : h);
		nextPosition = Vector2{ nextx, nexty };
	}
	else
	{
		// Left or Right
		float nextx = x + ((secd) ? 0 : w);
		float nexty = y + std::rand() % (int)h;
		nextPosition = Vector2{ nextx, nexty };
	}

	return nextPosition;
}
