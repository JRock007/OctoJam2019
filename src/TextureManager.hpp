#pragma once
#include "raylib.h"
#include <map>
#include <string>

class TextureManager
{
public:
	static void loadTexture(std::string textureName, std::string texturePath);
	static Texture& getTexture(std::string textureName);
private:
	static std::map<std::string, Texture2D> textures;
};