#pragma once
#include <vector>
#include "raylib.h"
#include "Node.hpp"
#include "GhostAction.hpp"
#include "Node.hpp"

class Scene: public Node {
public:
    void draw();
    virtual void update(float dt) = 0;

protected:
    Scene();
    ~Scene();
    Vector2 getInputAcceleration();
    GhostAction getInputAction();

    std::vector<std::shared_ptr<Node>> nodes;
};
