#include "Level1.hpp"
#include "Entities.hpp"

Level1::Level1() {
    // Create some nodes for testing
    /*std::shared_ptr<Table> table(new Table(300, 200));
    nodes.push_back(table);

    std::shared_ptr<Person> person(new Person(50, 70));
    nodes.push_back(person);
	*/

	spawnTable(300, 200);
	spawnTable(700, 300);
	spawnTable(500, 600);

	for (int i(0); i < 10; i++)
	{
		// Select random table
		auto table = *tables[std::rand() % tables.size()];
		spawnPerson(table);
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
    ghost.doAction(action);

    auto angle = Scene::getInputAngle();
    auto amplitude = Scene::getInputAmplitude();
    ghost.setAcceleration(angle, amplitude);
}
