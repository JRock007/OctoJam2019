//
//  Window.cpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

#include "Window.hpp"
#include "raylib.h"

Window::Window() {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "SHhhh!");
    SetTargetFPS(60);
}

Window::~Window() {
    setCursorEnabled(true);
}

void Window::setCursorEnabled(bool enabled) {
    if (enabled) {
        EnableCursor();
        ShowCursor();
    } else {
        DisableCursor();
        HideCursor();
    }
}

void Window::setTitle(const char* title) {
    SetWindowTitle(title);
}

void Window::toggleFullscreen() {
    ToggleFullscreen();
    _isFullscreen = !_isFullscreen;
}

bool Window::isFullscreen() {
    return _isFullscreen;
}
