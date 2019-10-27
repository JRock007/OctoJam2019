#pragma once
#include "Scene.hpp"
#include "TextureManager.hpp"

class Level1: public Scene {
public:
    Level1(Window&, TextureManager&);
    ~Level1();

    virtual void draw() override;
    virtual void update(float dt) override;
};
