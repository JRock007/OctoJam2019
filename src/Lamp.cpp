#include "Lamp.hpp"

Lamp::Lamp(float x, float y, Texture2D& texture) : 
	Interactable(x, y, 16, 16),
	turnedOn(true),
	texture(texture),
	spritesheet(16,16,texture.width,texture.height)
{
}

Lamp::~Lamp()
{

}

void Lamp::interact()
{
    toggle();
}

void Lamp::toggle()
{
    turnedOn = !turnedOn;
}

void Lamp::draw()
{
	Rectangle dst{x, y, w*SPRITES_SCALE, h*SPRITES_SCALE};
	int id = 0;
	if (isTurnedOn())
	{
		if (isHighlighted())
			id = 4;
		else
			id = 3;
	}
	else
	{
		if (isHighlighted())
			id = 2;
		else
			id = 1;
	}
	DrawTexturePro(texture, spritesheet.getSrcRect(id), dst, {}, 0.f, WHITE);
}
