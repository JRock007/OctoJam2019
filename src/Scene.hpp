#pragma once
#include <vector>
#include "raylib.h"
#include "Node.hpp"
#include "GhostAction.hpp"
#include "Node.hpp"
#include "Entities.hpp"
#include <memory>

class Scene: public Node {
public:
    virtual void draw() override;
    virtual void update(float dt) override;

protected:
    Scene();
    ~Scene();
    Vector2 getInputAcceleration();
    GhostAction getInputAction();
	// Spawn table to a given location
	void spawnTable(float x, float y);
	// Spawn person to a random table
	void spawnPerson(Table& table);

    Ghost ghost = Ghost(1280/2, 720/2);
    std::vector<std::shared_ptr<Node>> nodes;
	std::vector<std::shared_ptr<Table>> tables;
	std::vector<std::shared_ptr<Person>> persons;
};
