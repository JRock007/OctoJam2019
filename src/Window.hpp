#pragma once

class Window {
public:
    Window();
    ~Window();

    void setCursorEnabled(bool);
    void setTitle(const char*);
    void toggleFullscreen();

    bool isFullscreen();
    float getWidth();
    float getHeight();

private:
    bool _isFullscreen = false;
};
