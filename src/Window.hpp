//
//  Window.hpp
//  OctoJam2019
//
//  Created by Jean-Romain on 25/10/2019.
//  Copyright © 2019 JustKodding. All rights reserved.
//

class Window {
public:
    Window();
    ~Window();

    void setCursorEnabled(bool);
    void setTitle(const char*);
    void toggleFullscreen();
    bool isFullscreen();

private:
    bool _isFullscreen = false;
};
