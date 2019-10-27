#include "Scene.hpp"
#include "Constants.hpp"
#include "Utils.hpp"
#include <cstdlib>
#define _USE_MATH_DEFINES 
#include "math.h"
#include <cmath>
#include <limits>
#include "TextureManager.hpp"

Scene::Scene(Window& window, TextureManager& textureManager) :
	window(window),
	tilesetTexture(textureManager.getTexture("tileset")),
	maskTexture(textureManager.getTexture("mask")),
	ghost(window.getWidth() / 2, window.getHeight() / 2, textureManager.getTextureRef("ghost")),
	camera(ghost, window),
	mapWidth(window.getWidth()),
	mapHeight(window.getHeight()),
	mapLoader(textureManager.getTextureRef("tileset")),
	textureManager(textureManager)
{
    camera.jumpToPosition(ghost.getX(), ghost.getY());
};

Scene::~Scene() {
    // Release all the pointers we have
	for (auto node : nodes) {
		node.reset();
        node = nullptr;
	}
};

void Scene::drawBackground() {
    DrawRectangle(0, 0, mapWidth, mapHeight, BACKGROUND_COLOR);
}

void Scene::drawNodes() {
    // Delegate drawing to all the nodes
    for (auto& node: nodes) {
        node->draw();
    }
}

void Scene::drawGhost() {
    ghost.draw();

    // Compute score
    float score = 0;
    for (auto& person: persons) {
        score += person->getState() == PersonState::calm;
    }
    score /= persons.size();

    if (score == 0 && GetTime() > 5) {
        lost = true;
    }

    BeginBlendMode(BLEND_MULTIPLIED);
        float scale = 2 + 5 * score;

        // Darken the screen a bit
        unsigned char alpha = int(200 * (1 - score));
        DrawRectangle(0, 0, mapWidth, mapHeight, Color{0, 0, 0, alpha});

        // Show the mask
        float x = ghost.getDrawX() - scale * maskTexture.width / 2 + ghost.getW() / 2;
        float y = ghost.getDrawY() - scale * maskTexture.height / 2 + ghost.getH() / 2;

        DrawTexturePro(maskTexture,
                       Rectangle{ 0, 0, (float)maskTexture.width, (float)maskTexture.height },
                       Rectangle{ x, y, scale * (float)maskTexture.width, scale * (float)maskTexture.height },
                       Vector2{ 0, 0 },
                       0,
                       Fade(Color{255, 255, 255, 255}, 1.0f));
    EndBlendMode();
}

void Scene::draw() {
    drawBackground();
    drawNodes();
    drawGhost(); // Should be called last so the ghost is on top
}

void Scene::update(float dt) {
    // Delegate updating to all the nodes
    for (auto& node: nodes) {
        node->update(dt);
    }

    ghost.update(dt);
    ghost.clamp(0, 0, mapWidth, mapHeight);
    camera.update(dt);

	// Highlight closest item to ghost below a given range
    highlightedInteractable = getClosestNeighbor(ghost);

    if (highlightedInteractable != nullptr) {
        float dist = getEntityDistance(ghost, *highlightedInteractable);

        if (dist <= GHOST_ACTION_RANGE) {
            highlightedInteractable->setHighlight(true);
        } else {
            highlightedInteractable = nullptr;
        }
    }

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

    // Make ghost move
    auto angle = Scene::getInputAngle();
    auto amplitude = Scene::getInputAmplitude();
    ghost.setAcceleration(angle, amplitude);

    // Update remaining time
    if (remainingSurvivalTime > 0) {
        remainingSurvivalTime -= dt;
    } else {
        won = true;
    }
}

bool Scene::didWin() {
    return won;
}

bool Scene::didLose() {
    return lost;
}

void Scene::setMapSize(float width, float heigth) {
    mapWidth = width;
    mapHeight = heigth;
    camera.setBounds(-MAP_BORDER_SIZE, -MAP_BORDER_SIZE, mapWidth + MAP_BORDER_SIZE, mapHeight + MAP_BORDER_SIZE);

    // Resize game so the view is always the same
    float scaleW = window.getWidth() / GAME_WIDTH;
    float scaleH = window.getHeight() / GAME_HEIGHT;

    camera.camera.zoom = std::min(scaleW, scaleH);
}

std::vector<Person*> Scene::getNeighbors(Interactable& interactable, float range) {
    std::vector<Person*> neighbors = std::vector<Person*>();

    for (int i(0); i < persons.size(); i++) {
        float dist = getEntityDistance(interactable, *persons[i]);
        if (dist <= range) {
            neighbors.push_back(persons[i].get());
        }
    }

    return neighbors;
}

Interactable* Scene::getClosestNeighbor(Entity& entity, bool resetHighlights) {
    Interactable* closestNeighbor = nullptr;

    float minDist = std::numeric_limits<float>::max();;

    for (int i(0); i < interactables.size(); i++) {
        // Unhighlight interactable
        if (resetHighlights && interactables[i]->isHighlighted()) {
            interactables[i]->setHighlight(false);
        }

        // Compute dist and update pointer if necessary
        float dist = getEntityDistance(entity, *interactables[i]);
        if (dist < minDist) {
            minDist = dist;
            closestNeighbor = interactables[i].get();
        }
    }

    return closestNeighbor;
}

InteractionType Scene::getInteractionType(Interactable* interactable) {
    if (Book* book = dynamic_cast<Book*>(interactable)) {
        return InteractionType::book;
    } else if (Lamp* lamp = dynamic_cast<Lamp*>(interactable)) {
        if (lamp->isTurnedOn()) {
            return InteractionType::lampTurnOn;
        } else {
            return InteractionType::lampTurnOff;
        }
    }

    return InteractionType::unknown;
}

float Scene::getEntityDistance(Entity e1, Entity e2)
{
	return getMagnitude(
		e1.getX() + e1.getW() / 2,
		e1.getY() + e1.getH() / 2,
		e2.getX() + e2.getW() / 2,
		e2.getY() + e2.getH() / 2);
}

Camera2D& Scene::getCamera() {
    return camera.camera;
}

float Scene::getInputAngle() {
    float angle = 0;

    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {
        // Joystick input
        float x = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_X);
        float y = -GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_Y);
        angle = std::atan2(y, x);
    }

    if (IsGamepadAvailable(GAMEPAD_PLAYER1) && angle == 0) {
        // D-Pad as backup
        bool pressingRight = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
        bool pressingLeft = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
        bool pressingUp = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP);
        bool pressingDown = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
        angle = computeAngle(pressingLeft, pressingRight, pressingUp, pressingDown);
    }

    if (angle == 0) {
        // Keyboard as last hope
        bool pressingRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
        bool pressingLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        bool pressingUp = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
        bool pressingDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);
        angle = computeAngle(pressingLeft, pressingRight, pressingUp, pressingDown);
    }

    return angle;
}

float Scene::getInputAmplitude() {
    float amplitude = 0;

    if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {
        // Joystick input
        float xAccel = GHOST_ACCEL * GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_X);
        float yAccel = GHOST_ACCEL * GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_AXIS_LEFT_Y);
        amplitude = std::sqrt(std::pow(xAccel, 2) + std::pow(yAccel, 2));
    }

    if (IsGamepadAvailable(GAMEPAD_PLAYER1) && amplitude == 0) {
        // D-Pad as backup
        bool pressingRight = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
        bool pressingLeft = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
        bool pressingUp = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_UP);
        bool pressingDown = IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
        amplitude = computeAmplitude(pressingLeft, pressingRight, pressingUp, pressingDown);
    }

    if (amplitude == 0) {
        // Keyboard as last hope
        bool pressingRight = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
        bool pressingLeft = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
        bool pressingUp = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
        bool pressingDown = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);
        amplitude = computeAmplitude(pressingLeft, pressingRight, pressingUp, pressingDown);
    }

    return amplitude;
}

float Scene::computeAngle(bool left, bool right, bool up, bool down) {
    // Diagonal
    if (up && right) {
        return M_PI / 4;
    }
    if (up && left) {
        return 3 * M_PI / 4;
    }
    if (down && right) {
        return 7 * M_PI / 4;
    }
    if (down && left) {
        return 5 * M_PI / 4;
    }

    // Straight
    if (up) {
        return M_PI / 2;
    }
    if (down) {
        return 3 * M_PI / 2;
    }
    if (right) {
        return 0;
    }
    if (left) {
        return M_PI;
    }

    return 0;
}

float Scene::computeAmplitude(bool left, bool right, bool up, bool down) {
    float xAccel = 0;
    float yAccel = 0;

    if (up) {
        xAccel -= GHOST_ACCEL;
    }
    if (down) {
        xAccel += GHOST_ACCEL;
    }

    if (right) {
        yAccel += GHOST_ACCEL;
    }
    if (left) {
        yAccel -= GHOST_ACCEL;
    }

    return std::sqrt(std::pow(xAccel, 2) + std::pow(yAccel, 2));
}

GhostAction Scene::getInputAction() {
    /**
     Get which action the user is pressing
     Only triggered when pressing the key for the first time, holding it doesn't work
     Key names use qwerty input, but adapt to other keyboards
     */
    if (IsKeyPressed(KEY_E)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
        return GhostAction::interact;
    }

    if (IsKeyPressed(KEY_Q)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_FACE_LEFT)) {
        return GhostAction::shush;
    }

    if (IsKeyPressed(KEY_SPACE)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_TRIGGER_2)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_TRIGGER_2)) {
        return GhostAction::dash;
    }

    if (IsKeyPressed(KEY_ENTER)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_LEFT_TRIGGER_1)
        || IsGamepadButtonDown(GAMEPAD_PLAYER1, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) {
        return GhostAction::fusrodah;
    }

    return GhostAction::none;
}

void Scene::spawnTable(float x, float y)
{
	Table table(x, y, tilesetTexture, Rectangle{ 5 * 16,3 * 16,4 * 16,4 * 16 });
	// std::shared_ptr<Table> ptable(new Table(x, y));
	tables.push_back(std::make_shared<Table>(table));
	nodes.push_back(std::make_shared<Table>(table));
}

void Scene::spawnPerson(float x, float y, PersonOrientation orientation)
{
	Texture2D& personTexture = textureManager.getTextureRef("frontstudent");

	switch (orientation)
	{
	default:
		break;
	}

	Person person(x, y, personTexture, orientation);
	person.enter(); // Toggle visibility on


    auto personPtr = std::make_shared<Person>(person);
    persons.push_back(personPtr);
    nodes.push_back(personPtr);
}

void Scene::spawnPersonAroundTable(Table& table)
{
    // Spawn a person
    Vector2 nextPosition = table.getNextPosition();
    spawnPerson(nextPosition.x, nextPosition.y, PersonOrientation::down);
}

void Scene::spawnLamp(float x, float y)
{
    auto lamp = std::make_shared<Lamp>(Lamp(x, y, textureManager.getTextureRef("lamp")));
    interactables.push_back(lamp);
    nodes.push_back(lamp);
}

void Scene::spawnBook(float x, float y)
{
    auto book = std::make_shared<Book>(Book(x, y, textureManager.getTextureRef("book")));
    interactables.push_back(book);
    nodes.push_back(book);
}

void Scene::moveGhostTo(float x, float y)
{
    ghost.moveTo(x, y);
}
