#pragma once
#include "Scene.hpp"
#include "TextureManager.hpp"

class GameOverScene: public Scene {
public:
    GameOverScene(Window&, TextureManager&);
    ~GameOverScene();

    virtual void draw() override;
    virtual void update(float dt) override;
};
