#include "GameOverScene.hpp"
#include "Entities.hpp"
#include "InteractionType.hpp"

GameOverScene::GameOverScene(Window& window, TextureManager& textureManager) : Scene(window, textureManager) {
    // Set map size so the camera can move
    setMapSize(window.getWidth(), window.getHeight());
}

GameOverScene::~GameOverScene() {
    
}

void GameOverScene::draw() {
    // Fade background
    DrawRectangle(0, 0, mapWidth, mapHeight, Color{0, 0, 0, 100});

    // Show text
    float size = 35;
    float width = MeasureText("Game over :(", size);

    float x = window.getWidth() / 2 - width / 2;
    float y = window.getHeight() / 2 - size / 2;
    DrawText("Game over :(", x, y, size, RAYWHITE);
}

void GameOverScene::update(float dt) {}
