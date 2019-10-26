#include "Level1.hpp"
#include "Entities.hpp"
#include "InteractionType.hpp"

Level1::Level1(Window& window) : Scene(window) {
    // Set map size so the camera can move
    setMapSize(1.5 * window.getWidth(), 2 * window.getHeight());

    // Create some nodes for testing
	spawnLamp(800, 500);

	spawnTable(300, 200);
	spawnTable(700, 300);
	spawnTable(500, 600);

	spawnBook(710, 320);

	for (int i(0); i < 10; i++)
	{
		// Select random table
		auto table = *tables[std::rand() % tables.size()];
		spawnPersonAroundTable(table);
	}
}

Level1::~Level1() {
    
}

void Level1::draw() {
    Scene::draw();
}

void Level1::update(float dt) {
    Scene::update(dt);
}
