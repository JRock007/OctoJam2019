#pragma once
#include <vector>
#include "raylib.h"
#include "Node.hpp"
#include "GhostAction.hpp"
#include "Node.hpp"
#include "Entities.hpp"
#include <memory>

class Scene: public Node {
public:
    virtual void draw() override;
    virtual void update(float dt) override;

protected:
    Scene();
    ~Scene();
    Vector2 getInputAcceleration();
    GhostAction getInputAction();

    Ghost ghost = Ghost(1280/2, 720/2);
    std::vector<std::shared_ptr<Node>> nodes;
};
