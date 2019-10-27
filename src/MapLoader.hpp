#pragma once
#include "Scene.hpp"

class MapLoader {
public:
    static void spawnEntities(int entities[], Scene& scene, int width, int height);
    static void drawTiles(int tiles[], Scene& scene, int width, int height);
};
