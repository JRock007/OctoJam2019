//
//  main.cpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

#include "raylib.h"
#include "Window.hpp"

int main(void)
{
    // Initialization
    auto window = Window();
    window.toggleFullscreen();
    window.setCursorEnabled(false);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
