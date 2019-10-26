#include "Level1.hpp"
#include "Entities.hpp"

Level1::Level1() {
    // Create some nodes for testing
    std::shared_ptr<Table> table(new Table());
    nodes.push_back(table);

    std::shared_ptr<Person> person(new Person());
    nodes.push_back(person);
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
