#pragma once
#include "Node.hpp"

class Entity: public Node {
public:
    Entity();
    ~Entity();
    // Perform render operation
    virtual void draw();
    // Perform update and logic
    virtual void update(float dt);

    // Reposition entity to a give x and y
    void setPosition(float x, float y);
    // Reposition entity by giving an offset
    void move(float dx, float dy);

    // x getter
    float getX() { return x; }
    // y getter
    float getY() { return y; }

protected:
    float x;
    float y;
};
