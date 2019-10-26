#pragma once

class Interactable
{
public:
	virtual void setHighlight(bool highlight) { highlight = highlight; }
	virtual void interact() {}
	bool isHighlighted() { return highlight; }
protected:
	bool highlight;
};