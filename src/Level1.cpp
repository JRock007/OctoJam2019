#include "Level1.hpp"
#include "Entities.hpp"
#include "InteractionType.hpp"

Level1::Level1(Window& window) : Scene(window) {
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

    // Pass inputs to ghost
    auto action = Scene::getInputAction();
    if (action == GhostAction::interact) {
        // Catch this and directly interact with the item
        InteractionType type = getInteractionType(highlightedInteractable);

        if (highlightedInteractable != nullptr && type != InteractionType::unknown) {
            highlightedInteractable->interact();

            auto neighbors = getNeighbors(*highlightedInteractable);
            for (int i = 0; i < neighbors.size(); i++) {
                neighbors[i]->reactToInteraction(type);
            }
        }
    } else if (action != GhostAction::none) {
        ghost.doAction(action);
    }

    auto angle = Scene::getInputAngle();
    auto amplitude = Scene::getInputAmplitude();
    ghost.setAcceleration(angle, amplitude);
}
