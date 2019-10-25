#include "Person.hpp"

Person::Person() : Entity()
{
    disabled = false;
}

Person::~Person()
{

}

void Person::leave()
{
    disabled = true;
}

void Person::enter()
{
    disabled = false;
}