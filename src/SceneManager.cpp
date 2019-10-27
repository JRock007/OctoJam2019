#include "SceneManager.hpp"
#include "Constants.hpp"

SceneManager::SceneManager(Window& window, TextureManager& textureManager) :
    pauseScene(window, textureManager)
{
    
}

void SceneManager::draw() {
    /**
     * Draw all elements that use the camera
     */
    for (Scene* scene: scenes) {
        scene->draw();
    }
}

void SceneManager::drawHud() {
    /**
     * Draw elements "on top"
     */
    if (isPaused()) {
        pauseScene.draw();
    }

    if (transitionTimer > 0) {
        float advancement = transitionTimer / SCENE_TRANSITION_DURATION;
        unsigned char component = 255 * advancement;
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Color{0, 0, 0, component});
    }

    DrawFPS(10, 10);
}

Camera2D SceneManager::getCamera() {
    // We should always have at least one scene
    return scenes.front()->getCamera();
}

void SceneManager::update(float dt) {
    if (!isPaused()) {
        for (Scene* scene: scenes) {
            scene->update(dt);
        }
    }

    if (transitionTimer > 0) {
        transitionTimer -= dt;
    } else if (scenes.size() >= 2) {
        // Remove the old scene
        scenes.erase(scenes.begin());
    }

    if (scenes.back()->didWin()) {
        
    }
}

void SceneManager::pause() {
    paused = true;
}

void SceneManager::resume() {
    paused = false;
}

void SceneManager::moveToScene(Scene* scene) {
    scenes.push_back(scene);
    transitionTimer = SCENE_TRANSITION_DURATION;
    resume();
}
