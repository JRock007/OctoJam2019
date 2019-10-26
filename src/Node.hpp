#pragma once
#include "raylib.h"
#include "Constants.hpp"

class Node {
public:
    Node();
    virtual ~Node();
    virtual void draw();
    virtual void update(float dt);
};
