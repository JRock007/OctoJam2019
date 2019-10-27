#include "raylib.h"
#include "Window.hpp"
#include "Levels.hpp"
#include "Person.hpp"
#include <cstdlib>
#include <iostream>
#include "TextureManager.hpp"
#include "SceneManager.hpp"
#include <ctime>

/*
#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION            100
#endif
*/

int main(void)
{
    // Initialization
	std::srand((unsigned int)std::time(nullptr));

	// SetConfigFlags(FLAG_MSAA_4X_HINT);      // Enable Multi Sampling Anti Aliasing 4x (if available)
    auto window = Window();
    window.toggleFullscreen();
    window.setCursorEnabled(false);
	const int screenWidth = window.getWidth();
	const int screenHeight = window.getHeight();

	TextureManager textureManager;
	textureManager.loadTexture("tileset", "assets/Tileset.png");
	textureManager.loadTexture("ghost", "assets/Ghost_Spritesheet.png");
	textureManager.loadTexture("book", "assets/Book_Spritesheet.png");
	textureManager.loadTexture("backstudent", "assets/Back_Student_Spritesheet.png");
	textureManager.loadTexture("frontstudent", "assets/Front_Student_Spritesheet.png");
	textureManager.loadTexture("sidestudent", "assets/Profile_Student_Spritesheet.png");
	textureManager.loadTexture("mask", "assets/mask.png");
	textureManager.loadTexture("lamp", "assets/Lamp_Spritesheet.png");
	// Texture2D& tileset = textureManager.getTextureRef("tileset");

    auto sceneManager = SceneManager(window, textureManager);
    auto lvl1 = Level1(window, textureManager);
    auto lvl2 = Level2(window, textureManager);
    
    sceneManager.moveToScene(&lvl1);
    // sceneManager.moveToScene(&lvl2);

	float scale = 4;
	Rectangle tableSrc = { 5 * 16, 0, 4 * 16, 3 * 16 };
	Rectangle tableDst = { 500, 300, scale * 4 * 16, scale * 3 * 16 };
	Rectangle ghostSrc = { 10 * 16, 1 * 16, 1 * 16, 2 * 16 };
	Rectangle ghostDst = { 700, 500, scale * 1 * 16, scale * 2 * 16 };
//	Rectangle personSrc = { 5 * 16, 0, 4 * 16, 3 * 16 };
//	Rectangle personDst = { 500, 300, scale * 4 * 16, scale * 3 * 16 };

	// SHADERS
	// std::cout << GLSL_VERSION << std::endl;
	//Shader shader = LoadShader(0, FormatText("resources/shaders/glsl%i/fisheye.fs", GLSL_VERSION));
	// Create a RenderTexture2D to be used for render to texture
	// RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);


    // Main game loop
    while (!WindowShouldClose()) {
		ClearBackground(BLACK);

        // Update
        sceneManager.update(GetFrameTime());

        // Draw
        BeginDrawing();
            // Draw scenes
            BeginMode2D(sceneManager.getCamera());
                // BeginShaderMode(shader);
                sceneManager.draw();
                // EndShaderMode();
            EndMode2D();

            sceneManager.drawHud();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
