#include "AnimationManager.hpp"

AnimationManager::AnimationManager():
    Node()
{
    addAnimation(0, {0}, 0.f, false);
}

void AnimationManager::addAnimation(int idx, std::vector<int> frames, float period=1/12.f, bool repeat=true)
{
	animations[idx] = Animation(frames, period, repeat);
}

void AnimationManager::update(float dt)
{
    animations[current].update(dt);
}

void AnimationManager::draw()
{
    animations[current].draw();
}

int AnimationManager::getFrame()
{
    return animations[current].getFrame();
}

bool AnimationManager::isDone()
{
	return animations[current].isDone();
}

void AnimationManager::play(int idx, bool reset)
{
	if (current == idx && !reset)
		return;

	current = idx;
	animations[current].reset();
}
