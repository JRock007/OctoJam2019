#include "Animation.hpp"
#include <iostream>

Animation::Animation():
	Node(),
	elapsed(0),
	done(true),
	period(0),
	current(0),
	frames({ 0 }),
	repeat(false)
{

}

Animation::Animation(std::vector<int> frames, float period, bool repeat):
    Node(),
    elapsed(0),
    done(false),
    period(period),
    current(0),
    frames(frames),
    repeat(repeat)
{
}

void Animation::update(float dt)
{
    if (done && !repeat)
        return;

    elapsed += dt;
    if (elapsed >= period)
    {
        elapsed -= period;
        current ++;
        if (current >= frames.size())
        {
            current = 0;
            done = true;
        }
        else
        {
            if (done)
                done = false;
        }
    }
}

void Animation::draw()
{

}

int Animation::getFrame()
{
    return frames[current];
}

void Animation::reset()
{
	done = false;
	elapsed = 0.f;
	current = 0;
}
