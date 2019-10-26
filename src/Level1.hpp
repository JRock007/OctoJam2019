#pragma once
#include "Scene.hpp"

class Level1: public Scene {
public:
    Level1();
    ~Level1();

    virtual void draw();
    virtual void update(float dt);
};
