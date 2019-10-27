#include "Level1.hpp"
#include "Entities.hpp"
#include "InteractionType.hpp"

Level1::Level1(Window& window, TextureManager& textureManager) : Scene(window, textureManager) {
    // Set map size so the camera can move
    setMapSize(window.getWidth(), window.getHeight());

    int entities[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 171, 0, 0, 0, 0, 0, 180, 0, 0, 0, 0, 0, 0, 0, 0, 150, 150, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 171, 0, 0, 0, 0, 162, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 141, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    mapLoader.spawnEntities(entities, *this, mapWidth, mapHeight);
}

Level1::~Level1() {
    
}

void Level1::draw() {
    drawBackground();
    mapLoader.drawTiles(tiles, *this, mapWidth, mapHeight);
    drawNodes();
    drawGhost();
}

void Level1::update(float dt) {
    Scene::update(dt);

    if (timeSinceStart < MIN_TIME_BEFORE_BECOME_EXCITED) {
        return;
    }

    int limit = 1 / RANDOMLY_BECOME_EXCITED_PROBABILITY;
    float random = rand() % limit;

    if (random == (limit - 1)) {
        // Make a random person excited
        int tries = 0;
        while (tries < 100) {
            int i = rand() % persons.size();

            if (persons[i]->getState() == PersonState::calm) {
                persons[i]->becomeExcited();
                break;
            }
            tries += 1;
        }
    }
}
