#include "Interactable.hpp"

Interactable::Interactable(float x, float y, float w, float h) :
	Entity(x,y,w,h),
	highlight(false)
{
}

Interactable::~Interactable()
{
}
