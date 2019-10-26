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
    float getInputAngle();
    float getInputAmplitude();
    GhostAction getInputAction();
	// Spawn table to a given location
	void spawnTable(float x, float y);
	// Spawn person to a given location
	void spawnPerson(float x, float y);
	// Spawn person to a random table
	void spawnPersonAroundTable(Table& table);
	// Spawn a lamp to a given location
	void spawnLamp(float x, float y);
	// Spawn a book to a given location
	void spawnBook(float x, float y);

    Ghost ghost = Ghost(1280/2, 720/2);
    std::vector<std::shared_ptr<Node>> nodes;
	std::vector<std::shared_ptr<Table>> tables;
	std::vector<std::shared_ptr<Person>> persons;
	std::vector<std::shared_ptr<Interactable>> interactables;
};
