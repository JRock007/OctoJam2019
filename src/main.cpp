#include "raylib.h"
#include "Window.hpp"
#include "Level1.hpp"
#include "Person.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(void)
{
    // Initialization
	std::srand((unsigned int)std::time(nullptr));

    auto window = Window();
    window.toggleFullscreen();
    window.setCursorEnabled(false);
    
    auto lvl = Level1();
    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        BeginDrawing();

        ClearBackground(RAYWHITE);
        lvl.draw();
        lvl.update(GetFrameTime());

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
