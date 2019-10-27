#pragma once
#include "Scene.hpp"
#include "TextureManager.hpp"

class Credits: public Scene {
public:
    Credits(Window&, TextureManager&);
    ~Credits();

    virtual void draw() override;
    virtual void update(float dt) override;
};
