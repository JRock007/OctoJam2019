#pragma once
#include "Entity.hpp"
#include <iostream>

class Interactable:
	public Entity
{
public:
	Interactable(float x, float y, float w, float h);
	~Interactable();
	virtual void setHighlight(bool state) { 
		std::cout << "SET HIGHLIGHT: " << state << std::endl;
		highlight = state; 
	}
	virtual void interact() {}
	virtual void draw() override {}
	virtual void update(float dt) override {}
	bool isHighlighted() { return highlight; }
protected:
	bool highlight;
};