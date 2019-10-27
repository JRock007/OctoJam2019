#include "Book.hpp"

Book::Book(float x, float y, Texture2D& texture) : 
	Interactable(x, y, 20, 20),
	texture(texture),
	spritesheet(16,16,texture.width,texture.height),
	animated(false)
{
	animationManager.addAnimation(0, { 6,7,8 }, 1 / 12.f, false);
}

Book::~Book()
{

}

void Book::interact()
{
	if (!animated)
		flip();
}

void Book::flip()
{
	animated = true;
	animationManager.play(0, true);
}

void Book::update(float dt)
{
	if (animated)
	{
		animationManager.update(dt);
		if (animationManager.isDone())
		{
			animated = false;
		}
	}
}

void Book::draw()
{
	Rectangle dst{ x, y, w * SPRITES_SCALE, h * SPRITES_SCALE };
	int id = 0;
	if (animated)
	{
		id = animationManager.getFrame();
	}
	else
	{
		if (isHighlighted())
			id = 2;
		else
			id = 1;
	}
	Rectangle src = spritesheet.getSrcRect(id);
	DrawTexturePro(texture, src, dst, {}, 0.f, WHITE);
}
