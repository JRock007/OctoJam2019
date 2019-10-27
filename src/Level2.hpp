#pragma once
#include "Scene.hpp"

class Level2: public Scene {
public:
    Level2(Window&);
    ~Level2();

    virtual void draw() override;
    virtual void update(float dt) override;
};
