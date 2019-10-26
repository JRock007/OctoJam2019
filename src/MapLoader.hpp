#pragma once
#include "Scene.hpp"

class MapLoader {
public:
    static void loadEntities(int* entities[], Scene& scene, int width, int height);
    static void loadTiles(int* tiles[], Scene& scene, int width, int height);
};
