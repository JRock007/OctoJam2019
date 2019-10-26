#pragma once

class Interactable
{
public:
	virtual void setHighlight(bool highlight) = 0;
	virtual void interact() = 0;
	bool isHighlighted() { return highlight; }
protected:
	bool highlight;
};