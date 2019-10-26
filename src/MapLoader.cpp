#include "MapLoader.hpp"
#include "Constants.hpp"

void MapLoader::loadEntities(int* map[], Scene& scene, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int y = TILE_SIZE * (i % width);
        int x = TILE_SIZE * (i - y);

        switch (i) {
            case 1: // TODO: Chair
                break;

            case 2: // Lamp
                scene.spawnLamp(x, y);
                break;

            case 3: // Ghost
                scene.moveGhostTo(x, y);
                break;

            default:
                break;
        }
    }
}

void MapLoader::loadTiles(int* tiles[], Scene& scene, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int y = i % width;
        int x = i - y;

        switch (i) {
            default:
                break;
        }
    }
}
