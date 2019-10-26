#pragma once
#include "raylib.h"

class Node {
public:
    Node();
    virtual ~Node();
    virtual void draw();
    virtual void update(float dt);
};
