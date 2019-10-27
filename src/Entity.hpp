#pragma once
#include "Node.hpp"

class Entity: public Node {
public:
	Entity(float x=0, float y=0, float w=0, float h=0);
    ~Entity();
    // Perform render operation
    virtual void draw() override;
    // Perform update and logic
    virtual void update(float dt) override;

    // Reposition entity to a give x and y
    void setPosition(float x, float y);
    // Reposition entity by giving an offset
    void move(float dx, float dy);

	// x getter
	float getX() { return x; }
	// y getter
	float getY() { return y; }
	// w getter
	float getW() { return SPRITES_SCALE * w; }
	// h getter
	float getH() { return SPRITES_SCALE * h; }

protected:
    float x;
    float y;
	float w;
	float h;
};
