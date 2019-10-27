#include "MapLoader.hpp"
#include "Constants.hpp"
#include <iostream>

void MapLoader::spawnEntities(int map[], Scene& scene, int width, int height) {
    scene.setMapSize(width * SPRITES_SCALE * TILE_SIZE, height * SPRITES_SCALE * TILE_SIZE);

    for (int i = 0; i < width * height; i++) {
        int x = SPRITES_SCALE * TILE_SIZE * (i % width);
        int y = SPRITES_SCALE * TILE_SIZE * (i / width);

        switch (map[i]) {
            case 25: // Ghost
                scene.moveGhostTo(x, y);
                break;

            case 28: // Person
                scene.spawnPerson(x, y);
                break;

            case 2: // TODO: Lamp
                scene.spawnLamp(x, y);
                break;

            case 3: // TODO: Book
                scene.spawnBook(x, y);
                break;

            default:
                break;
        }
    }
}

void MapLoader::drawTiles(int tiles[], Scene& scene, int width, int height) {
    scene.setMapSize(width * SPRITES_SCALE * TILE_SIZE, height * SPRITES_SCALE * TILE_SIZE);

    for (int i = 0; i < width * height; i++) {
        int x = SPRITES_SCALE * TILE_SIZE * (i % width);
        int y = SPRITES_SCALE * TILE_SIZE * (i / width);

        switch (tiles[i]) {
            case 0:
                break;

            default:
                // Draw
                break;
        }
    }
}
