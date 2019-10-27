#include "Credits.hpp"
#include "Entities.hpp"
#include "InteractionType.hpp"

Credits::Credits(Window& window, TextureManager& textureManager) : Scene(window, textureManager) {
    // Set map size so the camera can move
    setMapSize(window.getWidth(), window.getHeight());
}

Credits::~Credits() {
    
}

void Credits::draw() {
    // Fade background
    DrawRectangle(0, 0, mapWidth, mapHeight, Color{0, 0, 0, 100});

    // Show text
    float size = 35;
    float width = MeasureText("Congrats!", size);

    float x = window.getWidth() / 2 - width / 2;
    float y = window.getHeight() / 2 - size / 2;
    DrawText("Congrats!", x, y, size, RAYWHITE);
}

void Credits::update(float dt) {}
