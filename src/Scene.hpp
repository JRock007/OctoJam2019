//
//  Scene.hpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

#pragma once
#include <vector>
#include "raylib.h"
#include "Node.hpp"
#include "GhostAction.h"
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

    std::vector<Node> nodes;
};
