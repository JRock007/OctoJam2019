#include "Entity.hpp"

Entity::Entity(float x, float y, float w, float h) :
	x(x), y(y), w(w), h(h)
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
