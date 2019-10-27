#pragma once
#include "raylib.h"
#include "Spritesheet.hpp"

class Scene;
class MapLoader {
public:
	MapLoader(Texture2D& tilesetTexture);
    void spawnEntities(int entities[], Scene& scene, int width, int height);
    void drawTiles(int tiles[], Scene& scene, int width, int height);
private:
	Texture2D& tilesetTexture;
	Spritesheet tilesetSpritesheet;
};
