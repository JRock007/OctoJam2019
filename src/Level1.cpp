#include "Level1.hpp"
#include "Entities.hpp"

Level1::Level1() {
    // Create some nodes for testing
    nodes.push_back(Ghost());
    nodes.push_back(Table());
    nodes.push_back(Person());
}

Level1::~Level1() {
    
}


void Level1::draw() {
    Scene::draw();
}

void Level1::update(float dt) {
    Scene::getInputAcceleration();
    Scene::getInputAction();
}
