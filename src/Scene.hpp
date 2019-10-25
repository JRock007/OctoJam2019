//
//  Scene.hpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

#pragma once
#include "raylib.h"
#include "Node.hpp"
#include "GhostAction.h"

class Scene: public Node {
public:
    void draw();
    virtual void update(float dt) = 0;

protected:
    Vector2 getInputAcceleration();
    GhostAction getInputAction();
};
