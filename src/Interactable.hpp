#pragma once
#include "Entity.hpp"
#include <iostream>

class Interactable:
	public Entity
{
public:
	Interactable(float x, float y, float w, float h);
	~Interactable();
	void setHighlight(bool state) { highlight = state; }
	virtual void interact() {}
	virtual void draw() override {}
	virtual void update(float dt) override {}
	bool isHighlighted() { return highlight; }
protected:
	bool highlight;
};