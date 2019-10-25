//
//  Scene.hpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

#pragma once
#include "Node.hpp"

class Scene: public Node {
public:
    void draw();
    virtual void update(float dt) = 0;
};
