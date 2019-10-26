#pragma once
#include <vector>
#include "raylib.h"
#include "Node.hpp"
#include "GhostAction.hpp"
#include "Node.hpp"
#include "Entities.hpp"

class Scene: public Node {
public:
    virtual void draw();
    virtual void update(float dt);

protected:
    Scene();
    ~Scene();
    float getInputAngle();
    float getInputAmplitude();
    GhostAction getInputAction();

    Ghost ghost = Ghost();
    std::vector<std::shared_ptr<Node>> nodes;
};
