#pragma once
#include "Scene.hpp"
#include "TextureManager.hpp"

class PauseScene: public Scene {
public:
    PauseScene(Window&, TextureManager&);
    ~PauseScene();

    virtual void draw() override;
    virtual void update(float dt) override;
};
