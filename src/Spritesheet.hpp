#pragma once

#include "raylib.h"

class Spritesheet
{
public:
	Spritesheet();
	Spritesheet(int frameW, int frameH, int imgW, int imgH);
	Rectangle getSrcRect(int id);
private:
	int frameW;
	int frameH;
	int imgW;
	int imgH;
	int nbColumns;
	int nbLines;
};