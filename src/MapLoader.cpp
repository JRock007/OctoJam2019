#include "MapLoader.hpp"
#include "Constants.hpp"

void MapLoader::loadEntities(int map[], Scene& scene, int width, int height) {
    scene.setMapSize(width * TILE_SIZE, height * TILE_SIZE);

    for (int i = 0; i < width * height; i++) {
        int y = TILE_SIZE * (i % width);
        int x = TILE_SIZE * (i - y);

        switch (map[i]) {
            case 28: // Chair (aka Person)
                scene.spawnPerson(x, y);
                break;

            case 2: // Lamp
                scene.spawnLamp(x, y);
                break;

            case 3: // Book
                scene.spawnBook(x, y);
                break;
                
            case 4: // Ghost
                scene.moveGhostTo(x, y);
                break;

            default:
                break;
        }
    }
}

void MapLoader::loadTiles(int tiles[], Scene& scene, int width, int height) {
    scene.setMapSize(width * TILE_SIZE, height * TILE_SIZE);

    for (int i = 0; i < width * height; i++) {
        int y = TILE_SIZE * (i % width);
        int x = TILE_SIZE * (i - y);

        switch (tiles[i]) {
            default:
                break;
        }
    }
}
