#include "Scene.hpp"
#include "raylib.h"

Scene::Scene() {};
Scene::~Scene() {};

void Scene::draw() {
    DrawFPS(10, 10);

    // Delegate drawing to all the nodes
    for (auto& node: nodes) {
        node.draw();
    }
}

Vector2 Scene::getInputAcceleration() {
    /**
     Get which direction the user is trying to go to
     Key names use qwerty input, but adapt to other keyboards
     */
    float xSpeed = 0;
    float ySpeed = 0;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        xSpeed += 10;
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        xSpeed -= 10;
    }

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        ySpeed += 10;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        ySpeed -= 10;
    }

    return Vector2{xSpeed, ySpeed};
}

GhostAction Scene::getInputAction() {
    /**
     Get which action the user is pressing
     Only triggered when pressing the key for the first time, holding it doesn't work
     Key names use qwerty input, but adapt to other keyboards
     */
    if (IsKeyPressed(KEY_E)) {
        return GhostAction::interact;
    }

    if (IsKeyPressed(KEY_Q)) {
        return GhostAction::shush;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        return GhostAction::dash;
    }

    if (IsKeyPressed(KEY_ENTER)) {
        return GhostAction::fusrodah;
    }

    return GhostAction::none;
}
