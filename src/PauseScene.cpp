#include "PauseScene.hpp"
#include "Entities.hpp"
#include "InteractionType.hpp"

PauseScene::PauseScene(Window& window, TextureManager& textureManager) : Scene(window, textureManager) {
    // Set map size so the camera can move
    setMapSize(window.getWidth(), window.getHeight());
}

PauseScene::~PauseScene() {
    
}

void PauseScene::draw() {
    // Fade background
    DrawRectangle(0, 0, mapWidth, mapHeight, Color{0, 0, 0, 100});

    // Show text
    float size = 20;
    float width = MeasureText("Paused", size);

    float x = window.getWidth() - width / 2;
    float y = window.getHeight() - size / 2;
    DrawText("Paused", x, y, size, RAYWHITE);
}

void PauseScene::update(float dt) {}
