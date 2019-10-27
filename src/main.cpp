#include "raylib.h"
#include "Window.hpp"
#include "Levels.hpp"
#include "Person.hpp"
#include <cstdlib>
#include <iostream>
#include "TextureManager.hpp"
#include "SceneManager.hpp"
#include <ctime>

int main(void)
{
    // Initialization
	std::srand((unsigned int)std::time(nullptr));

    auto window = Window();
    // window.toggleFullscreen();
    // window.setCursorEnabled(false);

	TextureManager textureManager;
	textureManager.loadTexture("tileset", "assets/Tileset_Prototype.png");
	// Texture2D& tileset = textureManager.getTextureRef("tileset");

    auto sceneManager = SceneManager(window, textureManager);
    auto lvl1 = Level1(window, textureManager);
    auto lvl2 = Level2(window, textureManager);
    
    // sceneManager.moveToScene(&lvl1);
    sceneManager.moveToScene(&lvl2);

	float scale = 4;
	Rectangle tableSrc = { 5 * 16, 0, 4 * 16, 3 * 16 };
	Rectangle tableDst = { 500, 300, scale * 4 * 16, scale * 3 * 16 };
	Rectangle ghostSrc = { 10 * 16, 1 * 16, 1 * 16, 2 * 16 };
	Rectangle ghostDst = { 700, 500, scale * 1 * 16, scale * 2 * 16 };
//	Rectangle personSrc = { 5 * 16, 0, 4 * 16, 3 * 16 };
//	Rectangle personDst = { 500, 300, scale * 4 * 16, scale * 3 * 16 };

    // Main game loop
    while (!WindowShouldClose()) {
		ClearBackground(BLACK);

        // Update
        sceneManager.update(GetFrameTime());

        // Draw
        BeginDrawing();
            // Draw scenes
            BeginMode2D(sceneManager.getCamera());
                sceneManager.draw();
            EndMode2D();

            sceneManager.drawHud();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
