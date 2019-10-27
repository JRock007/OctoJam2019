#pragma once

#include "Interactable.hpp"
#include "Entity.hpp"
#include "Table.hpp"
#include "Spritesheet.hpp"
#include "AnimationManager.hpp"

class Book:
    public Interactable
{
public:
    Book(float x, float y, Texture2D& texture);
    ~Book();
    void interact() override;
	void flip();
	virtual void update(float dt) override;
	virtual void draw() override;
private:
	Texture2D texture;
	Spritesheet spritesheet;
	AnimationManager animationManager;
	bool animated;
};
