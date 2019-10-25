//
//  Entity.cpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity()
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