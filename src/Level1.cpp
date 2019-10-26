#include "Level1.hpp"
#include "Entities.hpp"

Level1::Level1() {
    auto ghost = Ghost();
    nodes.push_back(ghost);

}

Level1::~Level1() {
    
}


void Level1::draw() {
    Scene::draw();
}

void Level1::update(float dt) {
    
}
