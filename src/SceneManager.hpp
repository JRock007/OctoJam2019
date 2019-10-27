#pragma once
#include "raylib.h"
#include "Scene.hpp"
#include "PauseScene.hpp"
#include "Window.hpp"
#include "TextureManager.hpp"

class SceneManager {
public:
    SceneManager(Window&, TextureManager&);
    void draw();
    void drawHud();
    void update(float dt);

    bool isPaused() { return paused; };
    void pause();
    void resume();
    void moveToScene(Scene* scene);
    Camera2D getCamera();

private:
    std::vector<Scene*> scenes; // List of scenes to draw
    bool paused = false;
    PauseScene pauseScene;

    float transitionTimer = 0;
};
