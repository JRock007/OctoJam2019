#include "MapLoader.hpp"
#include "Constants.hpp"
#include "Scene.hpp"
#include <iostream>

MapLoader::MapLoader(Texture2D& tilesetTexture) :
	tilesetTexture(tilesetTexture),
	tilesetSpritesheet(TILE_SIZE, TILE_SIZE, tilesetTexture.width, tilesetTexture.height)
{
}

void MapLoader::spawnEntities(int map[], Scene& scene, int width, int height) {
    scene.setMapSize(width * SPRITES_SCALE * TILE_SIZE, height * SPRITES_SCALE * TILE_SIZE);

    for (int i = 0; i < width * height; i++) {
        int x = SPRITES_SCALE * TILE_SIZE * (i % width);
        int y = SPRITES_SCALE * TILE_SIZE * (i / width);

        switch (map[i]) {
            case 192: // Ghost
                scene.moveGhostTo(x, y);
                break;

            case 141: // Person
                scene.spawnPerson(x, y, PersonOrientation::top);
                break;

            case 150: // Person
                scene.spawnPerson(x, y, PersonOrientation::down);
                break;

            case 162: // Person
                scene.spawnPerson(x, y, PersonOrientation::left);
                break;

            case 171: // Person
                scene.spawnPerson(x, y, PersonOrientation::right);
                break;

            case 180: // Book
                scene.spawnBook(x, y);
                break;

            case 188: // Lamp
                scene.spawnLamp(x, y);
                break;

            default:
                break;
        }
    }
}

void MapLoader::drawTiles(int tiles[], Scene& scene, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int x = SPRITES_SCALE * TILE_SIZE * (i % width);
        int y = SPRITES_SCALE * TILE_SIZE * (i / width);
		int w = SPRITES_SCALE * TILE_SIZE;
		int h = SPRITES_SCALE * TILE_SIZE;
		int id = tiles[i];

        switch (id) {
            case 0:
                break;

            default:
                // Draw
                Rectangle dst{ static_cast<float>(x), static_cast<float>(y), static_cast<float>(w), static_cast<float>(h) };
				DrawTexturePro(tilesetTexture, tilesetSpritesheet.getSrcRect(id), dst, {}, 0, WHITE);
                break;
        }
    }
}
