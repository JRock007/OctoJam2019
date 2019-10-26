#include "Scene.hpp"
#include "Constants.hpp"

Scene::Scene() {};

Scene::~Scene() {
    // Release all the pointers we have
    for (auto node: nodes) {
        node.reset();
    }
};

void Scene::draw() {
    DrawFPS(10, 10);

    // Delegate drawing to all the nodes
    for (auto& node: nodes) {
        node->draw();
    }

    // Draw the ghost last so it's on top
    ghost.draw();
}

void Scene::update(float dt) {
    // Delegate updating to all the nodes
    for (auto& node: nodes) {
        node->update(dt);
    }

    // Draw the ghost last so it's on top
    ghost.update(dt);
}

float Scene::getInputAngle() {
    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {
        // Joystick input
        float x = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_X);
        float y = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_Y);
        return std::atan2(y, x);
    } else {
        // Keyboard input
        bool pressingRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
        bool pressingLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        bool pressingUp = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
        bool pressingDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);

        // Diagonal
        if (pressingUp && pressingRight) {
            return M_PI / 4;
        }
        if (pressingUp && pressingLeft) {
            return 3 * M_PI / 4;
        }
        if (pressingDown && pressingRight) {
            return 7 * M_PI / 4;
        }
        if (pressingDown && pressingLeft) {
            return 5 * M_PI / 4;
        }

        // Straight
        if (pressingUp) {
            return M_PI / 2;
        }
        if (pressingDown) {
            return 3 * M_PI / 2;
        }
        if (pressingRight) {
            return 0;
        }
        if (pressingLeft) {
            return M_PI;
        }
    }

    // Just in case
    return 0;
}

float Scene::getInputAmplitude() {
    float xAccel = 0;
    float yAccel = 0;

    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {
        // Joystick input
        xAccel = GHOST_ACCEL * GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_X);
        yAccel = GHOST_ACCEL * GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_Y);
    } else {
        // Keyboard input
        bool pressingRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
        bool pressingLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        bool pressingUp = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
        bool pressingDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);

        if (pressingUp) {
            xAccel -= GHOST_ACCEL;
        }
        if (pressingDown) {
            xAccel += GHOST_ACCEL;
        }

        if (pressingRight) {
            yAccel += GHOST_ACCEL;
        }
        if (pressingLeft) {
            yAccel -= GHOST_ACCEL;
        }
    }

    return std::sqrt(std::pow(xAccel, 2) + std::pow(yAccel, 2));
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
