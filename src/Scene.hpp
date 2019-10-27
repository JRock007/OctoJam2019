#pragma once
#include <vector>
#include "raylib.h"
#include "Node.hpp"
#include "GhostAction.hpp"
#include "Node.hpp"
#include "Entities.hpp"
#include "Window.hpp"
#include "GhostCamera.hpp"
#include "Constants.hpp"
#include "InteractionType.hpp"
#include <memory>
#include "MapLoader.hpp"
#include "TextureManager.hpp"

class Scene: public Node {
public:
    Scene(Window&, TextureManager&);
    ~Scene();
    virtual void draw() override;
    virtual void update(float dt) override;

    Camera2D& getCamera();
    void setMapSize(float width, float heigth);

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
    // Teleport ghost to given position
    void moveGhostTo(float x, float y);

protected:

    Window& window;
    GhostCamera camera;
    float mapWidth;
    float mapHeight;

    float getInputAngle();
    float getInputAmplitude();
    GhostAction getInputAction();

    // Find neighbors of an interactable node
    std::vector<Person*> getNeighbors(Interactable&, float range=EVENT_ACTION_RANGE);
    // Get closest interactable object to entity
    Interactable* getClosestNeighbor(Entity& entity, bool resetHighlights=true);
    // Get the kind of interaction an interactable instance triggers
    InteractionType getInteractionType(Interactable* interactable);
	// Get distance between two entities
	float getEntityDistance(Entity e1, Entity e2);

    Ghost ghost;
    Interactable* highlightedInteractable = nullptr;
    std::vector<std::shared_ptr<Node>> nodes;
	std::vector<std::shared_ptr<Table>> tables;
	std::vector<std::shared_ptr<Person>> persons;
	std::vector<std::shared_ptr<Interactable>> interactables;
	Texture2D tilesetTexture;
	MapLoader mapLoader;

private:
    float computeAngle(bool left, bool right, bool up, bool down);
    float computeAmplitude(bool left, bool right, bool up, bool down);
};
