#include "Entity.hpp"

Entity::Entity() :
	x(0.f),
	y(0.f),
	w(0.f),
	h(0.f)
{

}

Entity::~Entity()
{
    
}

void Entity::draw()
{

}

void Entity::update(float dt)
{
}

void Entity::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Entity::move(float dx, float dy)
{
    x += dx;
    y += dy;
}
