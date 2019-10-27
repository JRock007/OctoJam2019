#include "Spritesheet.hpp"
#include "Constants.hpp"

Spritesheet::Spritesheet(int frameW, int frameH, int imgW, int imgH):
    frameW(frameW),
    frameH(frameH),
    imgW(imgW),
    imgH(imgH)
{
    nbColumns = imgW / frameW;
    nbLines = imgH / frameH;
}

Rectangle Spritesheet::getSrcRect(int id)
{
    if (id == 0) return Rectangle {};

    int line = (id - 1) / nbColumns;
    int col = id % nbColumns;

    int x = col * frameW;
    int y = line * frameH;

    return Rectangle{(float)x, (float)y, (float)frameW, (float)frameH};
}