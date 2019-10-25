//
//  Entity.hpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

#include "Node.hpp"

class Entity: public Node {
    virtual void draw() = 0;
    virtual void update(float dt) = 0;
};
