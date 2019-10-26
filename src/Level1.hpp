#pragma once
#include "Scene.hpp"

class Level1: public Scene {
public:
    Level1();
    ~Level1();

    void draw();
    void update(float dt);
};
