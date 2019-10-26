#include "raylib.h"
#include "Window.hpp"
#include "Levels.hpp"
#include "Person.hpp"
#include <cstdlib>
#include <iostream>
#include "TextureManager.hpp"
#include <ctime>

int main(void)
{
    // Initialization
	std::srand((unsigned int)std::time(nullptr));

    auto window = Window();
    // window.toggleFullscreen();
    // window.setCursorEnabled(false);
    
    auto lvl = Level2(window);

	TextureManager::loadTexture("tileset", "assets/Tileset_Prototype.png");

    // Main game loop
    while (!WindowShouldClose()) {
        ClearBackground(RAYWHITE);

        // Update
        lvl.update(GetFrameTime());

        // Draw
        BeginDrawing();
            // Draw nodes
            BeginMode2D(lvl.getCamera());
            lvl.draw();
            EndMode2D();

            // Draw HUD
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
