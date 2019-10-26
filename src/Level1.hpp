#pragma once
#include "Scene.hpp"

class Level1: public Scene {
public:
    Level1(Window&);
    ~Level1();

    virtual void draw() override;
    virtual void update(float dt) override;
};
