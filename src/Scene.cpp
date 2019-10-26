#include "Scene.hpp"
#include "Constants.hpp"
#include <cstdlib>

Scene::Scene() {};

Scene::~Scene() {
    // Release all the pointers we have
	for (auto node : nodes) {
		node.reset();
	}
	for (auto table : tables) {
		table.reset();
	}
	for (auto person : persons) {
		person.reset();
	}
};

void Scene::draw() {
    DrawFPS(10, 10);

    // Delegate drawing to all the nodes
    for (auto& node: nodes) {
        node->draw();
    }

    // Draw the ghost last so it's on top
    ghost.draw();
}

void Scene::update(float dt) {
    // Delegate updating to all the nodes
    for (auto& node: nodes) {
        node->update(dt);
    }

    // Draw the ghost last so it's on top
    ghost.update(dt);
}

Vector2 Scene::getInputAcceleration() {
    /**
     Get which direction the user is trying to go to
     Key names use qwerty input, but adapt to other keyboards
     */
    float xAccel = 0;
    float yAccel = 0;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        xAccel += GHOST_ACCEL;
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        xAccel -= GHOST_ACCEL;
    }

    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        yAccel -= GHOST_ACCEL;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        yAccel += GHOST_ACCEL;
    }

    return Vector2{xAccel, yAccel};
}

GhostAction Scene::getInputAction() {
    /**
     Get which action the user is pressing
     Only triggered when pressing the key for the first time, holding it doesn't work
     Key names use qwerty input, but adapt to other keyboards
     */
    if (IsKeyPressed(KEY_E)) {
        return GhostAction::interact;
    }

    if (IsKeyPressed(KEY_Q)) {
        return GhostAction::shush;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        return GhostAction::dash;
    }

    if (IsKeyPressed(KEY_ENTER)) {
        return GhostAction::fusrodah;
    }

    return GhostAction::none;
}

void Scene::spawnTable(float x, float y)
{
	Table table(x, y);
	std::shared_ptr<Table> ptable(new Table(x, y));
	tables.push_back(std::make_shared<Table>(table));
	nodes.push_back(std::make_shared<Table>(table));
}

void Scene::spawnPerson(Table& table)
{
	// Spawn a person
	Vector2 nextPosition = table.getNextPosition();
	Person person(nextPosition.x, nextPosition.y);
	person.enter(); // Toggle visibility on

	persons.push_back(std::make_shared<Person>(person));
	nodes.push_back(std::make_shared<Person>(person));
}
