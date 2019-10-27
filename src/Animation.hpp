#pragma once

#include <vector>
#include "Node.hpp"

class Animation :
    public Node
{
public:
	Animation();
    Animation(std::vector<int> frames, float period, bool repeat);
    virtual void update(float dt) override;
    virtual void draw() override;
    int getFrame();
	void reset();
private:
    int current;
    std::vector<int> frames;
    float period;
    bool done;
    bool repeat;
    float elapsed;
};