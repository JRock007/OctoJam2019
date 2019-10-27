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
	Texture2D& tileset = TextureManager::getTexture("tileset");
	float scale = 4;
	Rectangle tableSrc = { 5 * 16, 0, 4 * 16, 3 * 16 };
	Rectangle tableDst = { 500, 300, scale * 4 * 16, scale * 3 * 16 };
	Rectangle ghostSrc = { 10 * 16, 1 * 16, 1 * 16, 2 * 16 };
	Rectangle ghostDst = { 700, 500, scale * 1 * 16, scale * 2 * 16 };
//	Rectangle personSrc = { 5 * 16, 0, 4 * 16, 3 * 16 };
//	Rectangle personDst = { 500, 300, scale * 4 * 16, scale * 3 * 16 };

    // Main game loop
    while (!WindowShouldClose()) {
		ClearBackground(Color{ 106, 101, 118 });	
		//ClearBackground(RAYWHITE);

        // Update
        lvl.update(GetFrameTime());

        // Draw
        BeginDrawing();
            // Draw nodes
            BeginMode2D(lvl.getCamera());
            lvl.draw();
            EndMode2D();

			//DrawTexturePro(tileset, ghostSrc, ghostDst, Vector2{}, 0.f, WHITE);

            // Draw HUD
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
